#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *webView = new QWebEngineView;
    webView->setHtml("<H1>hello world</h1>");
    webView->show();
    return QApplication::exec();
}
