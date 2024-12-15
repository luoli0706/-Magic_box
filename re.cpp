#include "re.h"
#include "ui_re.h"


Re::Re(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Re)
{
    ui->setupUi(this);

    // 连接保存按钮到保存槽
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(saveBoxNumbers()));
    // 如果你的“返回”按钮已经连接到了to_back()槽，确保这部分代码仍然保留
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(to_back()));
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Re::Re_find);
    connect(ui->pushButton,&QPushButton::clicked,this,&Re::to_next);
    connect(this,&Re::gift,dr2,&Dialog_re2::ac);
}
void Re::load_to_list(const QString&num,const QString&phone){
    this->nums.append(num);
    this->phones.append(phone);

}
void Re::to_next(){
    dr1->show();
};
void Re::Re_find(){
    dr2->show();
    qDebug()<<"信号已经接受";
    if (!file->open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "无法打开文件用于写入";
        return;
    }
    QString s;
    QString s2;
    QTextStream out(file2);
    for(int i=0;i<nums.size();i++){
    out<<"待归还盒子编号：";
        out << nums[i] << "\n";
    out<<"待归还盒子的原持有者的联系方式：";
    out<<phones[i]<<"\n";
    s+=nums[i]+" ";
    s2+=phones[i]+" ";
    }// 将编号写入文件，每行一个编号
    emit gift(s,s2);
    file->close();
}
Re::~Re()
{
    delete ui;
    delete file;
    delete dr1;
    delete dr2;
    delete file2;
}

// 保存盒子编号到文本文件
void Re::saveBoxNumbers()
{
    QString boxNumber = ui->lineEdit->text(); // 获取输入框内容
    if (!file->open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "无法打开文件用于写入";
        return;
    }

    QTextStream out(file);
    out<<"已归还盒子编号：";
    out << boxNumber << "\n"; // 将编号写入文件，每行一个编号
    file->close();

    qDebug() << "盒子编号已保存：" << boxNumber;
}

void Re::to_back() {
    emit quitr();
    this->hide();
}

// 这两个函数目前是空的，如果你不需要处理这些按钮的点击事件，可以保留为空或删除
void Re::on_pushButton_clicked()
{

}

void Re::on_pushButton_2_clicked()
{

}


void Re::on_pushButton_3_clicked()
{

}

