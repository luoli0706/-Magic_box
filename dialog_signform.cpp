#include "dialog_signform.h"
#include "ui_dialog_signform.h"

Dialog_signform::Dialog_signform(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_signform)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&QDialog::close);
}

Dialog_signform::~Dialog_signform()
{
    delete ui;
}

void Dialog_signform::on_pushButton_clicked()
{

}

