#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QFileDialog>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

QImage blurImage (QImage image,int blurRadius)
{
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(image));
    //
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result (image.size(),QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter,QRectF(0,0,image.width(),image.height()));
    return result;
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //
    QWidget *mainWindow = new QWidget;
    mainWindow->setObjectName(QString::fromUtf8("BlurEditor"));

    auto *viewer = new QLabel(mainWindow);

    auto *slider = new QSlider(mainWindow);
    slider->setOrientation(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(10);

    auto *button = new QPushButton("Open",mainWindow);
    auto *verticalLayout = new QVBoxLayout(mainWindow);

    verticalLayout->addWidget(viewer);
    verticalLayout->addWidget(slider);
    verticalLayout->addWidget(button);


    QObject::connect(button,&QPushButton::clicked,[viewer,slider]()
    {
        QString filePath = QFileDialog::getOpenFileName(nullptr,"Open jpg picture",
                                                        "C:/files/images","jpg file(*.jpg)");
        QImage image  (filePath);
        QImage imageOut = blurImage(QImage (filePath),slider->sliderPosition());

        viewer->setPixmap(QPixmap::fromImage(imageOut).scaled(viewer->width(),viewer->height(),Qt::KeepAspectRatio));
        QObject::connect(slider,&QSlider::valueChanged,[slider,viewer,filePath]()
        {
            QImage imageOut = blurImage(QImage (filePath), slider->sliderPosition());
            viewer->setPixmap(QPixmap::fromImage(imageOut).scaled(viewer->width(),viewer->height(),Qt::KeepAspectRatio));
        });
    });
    mainWindow->resize(460, 480);
    mainWindow->show();
    return QApplication::exec();
}
#include <main.moc>
