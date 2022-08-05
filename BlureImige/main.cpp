#include <QApplication>
#include <QtGui/QtGui>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QPainter>
#include <iostream>


QImage blurImage (QImage source)
{
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0, 0, source.width(), source.height()));
    return result;
}

void processSingleImage(QString sourceFile, QString destFile)
{
    auto blured = blurImage(QImage(sourceFile));
    blured.save(destFile);
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QDir sourceDir ("C:/files/images");
    QDir destDir ("C:/files/blurImages");
    auto images = sourceDir.entryList(QStringList()<<"*.jpg"<<"*.JPG",QDir::Files);
    QElapsedTimer timer;
    timer.start();
    QList<QFuture<void>> handlers;
    for(auto &filename:images)
    {
        handlers.append(QtConcurrent::run(processSingleImage,sourceDir.path()+"/"+filename,
                            destDir.path()+"/"+"blur_"+filename));
    }
    for(auto & f:handlers){
        f.waitForFinished();
    }
    std::cout<<"time: "<<timer.elapsed()<<" ms"<<std::endl;
    return a.exec();
}
#include <main.moc>