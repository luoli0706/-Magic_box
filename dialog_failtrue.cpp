#include "dialog_failtrue.h"
#include "ui_dialog_failtrue.h"

Dialog_failtrue::Dialog_failtrue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_failtrue)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&QDialog::close);
}

Dialog_failtrue::~Dialog_failtrue()
{
    delete ui;
}

void Dialog_failtrue::on_pushButton_clicked()
{

}

