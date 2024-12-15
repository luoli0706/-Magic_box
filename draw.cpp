#include "draw.h"
#include "ui_draw.h"

Draw::Draw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Draw)
{
    ui->setupUi(this);
    ui->label->setPixmap(*pixmap);
    ui->label->setScaledContents(true);
    ui->label_2->setPixmap(*pixmap2);
    ui->label_2->setScaledContents(true);
    ui->label_3->setPixmap(*pixmap3);
    ui->label_3->setScaledContents(true);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(to_clear()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(wait()));
    connect(this,SIGNAL(st()),this,SLOT(to_draw()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(to_back()));
}

Draw::~Draw()
{
    delete ui;
    delete pixmap;
    delete pixmap2;
    delete pixmap3;
    delete pixmap4;
}

void Draw::on_pushButton_2_clicked()
{

}
void Draw::to_back(){
    emit quitr();
    this->hide();
}



void Draw::on_pushButton_clicked()
{

}
void Draw::wait(){
    QThread::sleep(2);
    emit st();

}
QPixmap* Draw::random(QVector<QPixmap*>& q) {

    // 定义概率分布

    std::vector<double> probabilities = {0.008, 0.03, 0.11, 0.832};

    // 计算累积分布函数（CDF）

    std::vector<double> cdf(probabilities.size());

    cdf[0] = probabilities[0];

    for (size_t i = 1; i < probabilities.size(); ++i) {

        cdf[i] = cdf[i - 1] + probabilities[i];

    }



    // 使用QTime作为种子

    QTime time = QTime::currentTime();

    qint64 seed = time.msec() + (time.second() * 1000LL) + (time.hour() * 3600000LL);

    // 注意：这里没有使用日期部分，因为QTime不包含日期



    // 创建随机数生成器和分布对象

    std::default_random_engine gen(static_cast<unsigned int>(seed % UINT_MAX));

    // 注意：将seed转换为unsigned int，并确保它在unsigned int的范围内

    // 如果seed可能超过UINT_MAX，则使用seed的模运算来限制其范围

    std::uniform_real_distribution<> dis(0.0, 1.0);



    // 生成随机数并映射到索引

    double random_value = dis(gen);

    auto it = std::lower_bound(cdf.begin(), cdf.end(), random_value);

    int index = std::distance(cdf.begin(), it);



    // 确保索引不越界（虽然在这个例子中不应该发生）

    if (index >= q.size()) {

        index = q.size() - 1;

    }



    // 返回对应的QPixmap指针

    return q[index];

}
void Draw::to_draw(){
    QVector<QPixmap*> pics={pixmap,pixmap2,pixmap3,pixmap4};
    QPixmap *result=random(pics);
    ui->label_4->setPixmap(*result);
    ui->label_4->setScaledContents(true);
}
void Draw::to_clear(){
    ui->label_4->clear();
}
