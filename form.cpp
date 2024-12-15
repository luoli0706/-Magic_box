#include "form.h"
#include "ui_form.h"
#include"signform.h"



Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    Init();

}

Form::~Form()
{
    delete ui;
    delete re;
    delete survey;
    delete sf;
}
void Form::Init(){
    connect(re,SIGNAL(quitr()),this,SLOT(goshow()));
    connect(sf,SIGNAL(quitr()),this,SLOT(goshow()));
    connect(survey,SIGNAL(quitr()),this,SLOT(goshow()));
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Form::hide);
    connect(ui->pushButton_2,&QPushButton::clicked,sf,&SignForm::show);
    connect(ui->pushButton,&QPushButton::clicked,this,&Form::hide);
    connect(ui->pushButton,&QPushButton::clicked,re,&Re::show);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Form::hide);
    connect(ui->pushButton_3,&QPushButton::clicked,survey,&Survey::show);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(to_back()));
    connect(sf,&SignForm::re_to,re,&Re::load_to_list);
}
void Form::goshow(){
    this->show();
}

void Form::on_pushButton_2_clicked()
{


}


void Form::on_pushButton_clicked()
{


}


void Form::on_pushButton_3_clicked()
{


}


void Form::on_pushButton_4_clicked()
{

}
void Form::to_back(){
    emit quitr();
    this->hide();
}

