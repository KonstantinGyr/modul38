#include <QApplication>
#include <QPushButton>
#include "blurerwindow.h"
#include "./ui_blurApp.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BlurerMainWindow window( nullptr);
    Ui::MainWindow blurer;
    blurer.setupUi(&window);
    window.label = blurer.label;
    window.resize(240, 480);
    window.show();
    return QApplication::exec();
}
