#include <QApplication>
#include <QtGui/QtGui>
#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *webView = new QWebEngineView;
    webView->setUrl(QUrl("http://skillbox.ru"));
    webView->show();
    return QApplication::exec();
}
