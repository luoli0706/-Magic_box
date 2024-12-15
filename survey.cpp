#include "survey.h"
#include "ui_survey.h"

Survey::Survey(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Survey)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(to_back()));

    connect(ui->pushButton,&QPushButton::clicked,this,&Survey::a1);
     connect(ui->pushButton_2,&QPushButton::clicked,this,&Survey::a2);
     connect(ui->pushButton_3,&QPushButton::clicked,this,&Survey::a3);
}

Survey::~Survey()
{
    delete ui;
}

void Survey::on_pushButton_4_clicked()
{

}

void Survey::to_back(){
    emit quitr();
    this->hide();
}
void Survey::a1(){
    this->cn3++;
    if((this->cn3+this->cn1+this->cn2)>9.0){
        ui->lineEdit_2->setText(QString::number(this->cn3*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_3->setText(QString::number(this->cn2*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_4->setText(QString::number(this->cn1*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
    }
}
void Survey::a2(){
    this->cn2++;
    if(this->cn3+this->cn1+this->cn2>9){
        ui->lineEdit_2->setText(QString::number(this->cn3*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_3->setText(QString::number(this->cn2*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_4->setText(QString::number(this->cn1*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
    }
}
void Survey::a3(){
    this->cn1++;
    if(this->cn3+this->cn1+this->cn2>9){
        ui->lineEdit_2->setText(QString::number(this->cn3*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_3->setText(QString::number(this->cn2*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
        ui->lineEdit_4->setText(QString::number(this->cn1*1.0/(this->cn1+this->cn2+this->cn3)*1.0));
    }
}
void Survey::on_pushButton_clicked()
{

}


void Survey::on_pushButton_2_clicked()
{

}

void Survey::on_pushButton_3_clicked()
{

}

