#include <QApplication>
#include <QtGui/QtGui>
#include <QWebEngineView>
#include <QPlainTextEdit>

#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //
    QWidget mainWindow;
    QHBoxLayout hbox(&mainWindow);

    auto *webView = new QWebEngineView(&mainWindow);
    auto *htmlEdit = new QPlainTextEdit(&mainWindow);

    hbox.addWidget(htmlEdit);
    hbox.addWidget(webView);
   // QObject::connect(htmlEdit,&QPlainTextEdit::textChanged(),webView,&QWebEngineView::setHtml())

    mainWindow.show();
    return QApplication::exec();
}
#include <main.moc>
