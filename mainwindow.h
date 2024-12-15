#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#pragma once
#include <QFile>
#include"form.h"
#include"Logic.h"
#include"dialog_failtrue.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void showMainWindow();
    void on_MainWindow_destroyed();


protected:


private:
    Ui::MainWindow *ui;
    Form *f=new Form;
    Dialog_failtrue *df=new Dialog_failtrue;
    QPixmap *pixmap5=new QPixmap(":/new/prefix1/pic/cloud.png");
    QFile *file=new QFile("../../doc/information.txt");

    void Init();
};
#endif // MAINWINDOW_H
