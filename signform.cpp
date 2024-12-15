#include "signform.h"
#include "ui_signform.h"

SignForm::SignForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignForm)
{
    ui->setupUi(this);
    ui->pushButton_3->setEnabled(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    connect(draw,SIGNAL(quitr()),this,SLOT(goshow()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(to_back()));
    connect(ui->pushButton,&QPushButton::clicked,this,&SignForm::close);
    connect(ui->pushButton,&QPushButton::clicked,draw,&Draw::show);
    connect(ui->pushButton_3,&QPushButton::clicked,ds,&QDialog::show);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&SignForm::to_re);
    connect(ui->lineEdit_16, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_11, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_10, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_12, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_13, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_14, &QLineEdit::textChanged, this, &SignForm::validateInput);
    connect(ui->lineEdit_17, &QLineEdit::textChanged, this, &SignForm::validateInput);


}

SignForm::~SignForm()
{
    delete ui;
    delete draw;
    delete ds;
}

void SignForm::on_pushButton_2_clicked()
{

}
void SignForm::to_back(){
    emit quitr();
    this->hide();
}
void SignForm::goshow(){
    this->show();
}
void SignForm::validateInput(){
    QString phone = ui->lineEdit_16->text();
    QString idNumber = ui->lineEdit_11->text();

    bool isValid = (phone.length() == 11) && (idNumber.length() == 18);

    if (isValid)
    {
        // 输入有效，启用按钮3并隐藏错误提示
        ui->pushButton_3->setEnabled(true);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
    }
    else
    {
        // 输入无效，禁用按钮3并显示错误提示
        ui->pushButton_3->setEnabled(false);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label->setText("手机号码应为11位");
        ui->label_2->setText("身份证号应为18位。");// 设置错误提示文本
    }
    if(ui->lineEdit_10->text().isEmpty()){
        ui->pushButton_3->setEnabled(false);
        ui->label_3->setVisible(true);
    }
    else{
        ui->pushButton_3->setEnabled(true);
        ui->label_3->setVisible(false);
    }
    if(ui->lineEdit_12->text().isEmpty()){
        ui->pushButton_3->setEnabled(false);
        ui->label_4->setVisible(true);
    }
    else{
        ui->pushButton_3->setEnabled(true);
        ui->label_4->setVisible(false);
    }
    if(ui->lineEdit_13->text().isEmpty()){
        ui->pushButton_3->setEnabled(false);
        ui->label_5->setVisible(true);
    }
    else{
        ui->pushButton_3->setEnabled(true);
        ui->label_5->setVisible(false);
    }
    if(ui->lineEdit_14->text().isEmpty()){
        ui->pushButton_3->setEnabled(false);
        ui->label_6->setVisible(true);
    }
    else{
        ui->pushButton_3->setEnabled(true);
        ui->label_6->setVisible(false);
    }
    if(ui->lineEdit_17->text().isEmpty()){
        ui->pushButton_3->setEnabled(false);
        ui->label_7->setVisible(true);
    }
    else{
        ui->pushButton_3->setEnabled(true);
        ui->label_7->setVisible(false);
    }
}
void SignForm::on_pushButton_clicked()
{


}

void SignForm::to_re(){
   QString num=ui->lineEdit_18->text();
   QString phone=ui->lineEdit_17->text();
    emit re_to(num,phone);
   qDebug()<<"信号已经发射";
}
void SignForm::on_pushButton_3_clicked()
{
    QFile file("../../doc/information_person.txt");

    // 以写入模式打开文件（如果文件不存在则创建它）
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing:" << file.errorString();

    }

    // 创建QTextStream对象，用于写入文本
    QTextStream out(&file);

    // 写入QString到文件
    out<<"姓名: ";
    out << ui->lineEdit_10->text();
    out<<"\n";
    out<<"身份证号: ";
    out << ui->lineEdit_11->text();
    out<<"\n";
    out<<"登机牌: ";
    out << ui->lineEdit_12->text();
    out<<"\n";
    out<<"出发地: ";
    out << ui->lineEdit_13->text();
    out<<"\n";
    out<<"目的地: ";
    out << ui->lineEdit_14->text();
    out<<"\n";
    out<<"手机机型:  ";
    out << ui->lineEdit_15->text();
    out<<"\n";
    out<<"手机号码:";
    out << ui->lineEdit_16->text();
    out<<"\n";
    out<<"备选联系方式: ";
    out << ui->lineEdit_17->text();
    out<<"\n\n";

    // 关闭文件
    file.close();
}


