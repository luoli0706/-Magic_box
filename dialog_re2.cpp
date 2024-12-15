#include "dialog_re2.h"
#include "ui_dialog_re2.h"

Dialog_re2::Dialog_re2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_re2)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&QDialog::hide);
}

Dialog_re2::~Dialog_re2()
{
    delete ui;
}
void Dialog_re2::ac(const QString&s1,const QString&s2){
    ui->lineEdit_2->setText(s1);
    ui->lineEdit_4->setText(s2);
}
void Dialog_re2::on_pushButton_clicked()
{

}

