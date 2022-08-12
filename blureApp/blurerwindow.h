//
// Created by Kot on 12.08.2022.
//

#ifndef BLUREAPP_BLURERWINDOW_H
#define BLUREAPP_BLURERWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLabel>
#include <QFileDialog>

class BlurerMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    BlurerMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}
    QLabel *label = nullptr;
    QString filePath;
    QPicture *picture;

public slots:
    void open(){
    filePath = QFileDialog::getOpenFileName(nullptr,"Open jpg picture",
                                            "C:/files","jpg file(*.jpg,*.JPG");

};
    void slider();
};

#endif //BLUREAPP_BLURERWINDOW_H
