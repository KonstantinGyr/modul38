#include <QApplication>
#include <QtGui/QtGui>
#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QSizePolicy>
#include <QHBoxLayout>
#include <QIODevice>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //
    QWidget mainWindow;
    auto *horizontalLayout = new QHBoxLayout (&mainWindow);
    auto *webView = new QWebEngineView(&mainWindow);
    auto *htmlEdit = new QPlainTextEdit(&mainWindow);
    horizontalLayout->addWidget(htmlEdit,1);
    horizontalLayout->addWidget(webView,1);
    QSizePolicy sizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(0);
    webView->setSizePolicy(sizePolicy);
    htmlEdit->setSizePolicy(sizePolicy);
    mainWindow.resize(1000,640);
    // QString fileName = QFileDialog::getOpenFileName();
    // QFile file(fileName);
    // QTextStream out(&file);
    // QString output = out.readAll();
    QString string = "<html><body><h1>HTML Previewer</h1>"
                     " <p>This example shows you how to use QWebEngineView to"
                     " preview HTML data written in a QPlainTextEdit.</p>"
                     " </body></html>";
    htmlEdit->setPlainText(string);
     webView->setHtml(string);
     QObject::connect(htmlEdit,&QPlainTextEdit:: textChanged,[htmlEdit,webView]()
     {
    QString content = htmlEdit->toPlainText();
    webView->setHtml(content);
     });

    mainWindow.show();
    return QApplication::exec();
}
#include <main.moc>
