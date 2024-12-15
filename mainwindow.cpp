#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet("color:red");
    ui->label->setPixmap(*pixmap5);
    ui->label->setScaledContents(true);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f;
    delete df;
    delete pixmap5;
    delete file;
}

void MainWindow::Init(){
    connect(f,SIGNAL(quitr()),this,SLOT(showMainWindow()));//接受回退请求而显示

    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::close);
}
void MainWindow::on_pushButton_clicked()
{

    QString text = ui->lineEdit->text();
    QString text2 = ui->lineEdit_2->text();
    CrewMemberList cr(":/new/prefix1/doc/crew_member_list.txt");
    cr.print();
    bool vr=cr.verify(text,text2);
    if(vr){

    // 以写入模式打开文件（如果文件不存在则创建它）
        if (!file->open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing:" << file->errorString();

    }

    // 创建QTextStream对象，用于写入文本
    QTextStream out(file);

    // 写入QString到文件
    out<<"工号:";
    out << text;
    out<<"\n";
    out<<"密码:";
    out << text2;
    out<<"\n";


    // 关闭文件
    file->close();

    qDebug() << "Data written to file successfully.";
    MainWindow::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::hide);
    connect(ui->pushButton,&QPushButton::clicked,f,&QWidget::show);
    //this->close();
    }
    else{
        connect(ui->pushButton,&QPushButton::clicked,df,&QDialog::show);
    }


}

void MainWindow::showMainWindow()
{

    this->show(); // 重新显示主窗口

}
void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{


}


void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{

}


void MainWindow::on_MainWindow_destroyed()
{

}

