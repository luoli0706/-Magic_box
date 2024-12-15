#include "WaitWidge.h"
#include <QPainter>
#include <QTimer>
#include<QTransform>

// 静态变量，用于记录旋转次数
static int count = 0;

WaitWidge::WaitWidge(QWidget *parent)
    : QWidget(parent)
{
    // 设置窗口标志为无边框和工具窗口
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    // 设置窗口属性为透明背景
    setAttribute(Qt::WA_TranslucentBackground, true);

    // 加载等待动画图片
    m_pPixmap = new QPixmap(":/new/prefix1/Su7.png");

    // 创建定时器，用于定时更新动画
    m_pTimer = new QTimer(this);

    // 连接定时器的 timeout 信号到更新槽函数
    connect(m_pTimer, &QTimer::timeout, [=]{
        update(); // 更新窗口，触发 paintEvent
    });

    // 启动定时器，每 50 毫秒触发一次
    m_pTimer->start(50);
}

WaitWidge::~WaitWidge() {}

// 重载 paintEvent 方法
void WaitWidge::paintEvent(QPaintEvent *)
{
    // 创建 QPainter 对象，用于绘制
    QPainter painter(this);
    // 设置绘制选项
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);

    // 计算绘制区域，使图片居中
    QRect trect((rect().width() - 128)/2, (rect().height() - 128)/2, 128, 128);
    // 创建 QMatrix 对象，用于旋转图片
    QTransform matrix;
    // 旋转图片，每次旋转 10 度
    matrix.rotate((10 * (count++)) % 360);
    // 绘制旋转后的图片
    painter.drawPixmap(trect, m_pPixmap->transformed(matrix, Qt::SmoothTransformation));
}
