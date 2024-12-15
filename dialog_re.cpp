#include "dialog_re.h"
#include "ui_dialog_re.h"

Dialog_re::Dialog_re(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_re)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&QDialog::hide);
}

Dialog_re::~Dialog_re()
{
    delete ui;
}

void Dialog_re::on_pushButton_clicked()
{

}

