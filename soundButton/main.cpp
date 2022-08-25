#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QMediaPlayer>
#include <QTimer>
#include <QMediaContent>

class ImageButton :public QPushButton
{
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void  keyPressEvent(QKeyEvent *e)override;

public slots:
    void setUp();
    void setDown();

private:
    QMediaPlayer *player = new QMediaPlayer;
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("stop");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    mButtonUpPixmap = QPixmap("button_up.png");
    mButtonDownPixmap = QPixmap("button_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    player->setMedia(QUrl::fromLocalFile("sound.mp3"));
    player->setVolume(100);
    connect(this,&QPushButton::clicked,this,&ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(),mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    return setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    player->play();
    update();
    QTimer::singleShot(200, this,&ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ImageButton button( nullptr);
    button.setFixedSize(100, 100);
    button.move(1000,400);
   /* auto *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("C:/files/sound.mp3"));
    player->setVolume(100);
    QObject::connect(&button,&QPushButton::clicked,[&player]()
    {
        player->play();
    });*/
    button.show();
    return QApplication::exec();
}
#include <main.moc>
