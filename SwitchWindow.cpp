#include "SwitchWindow.h"
#include <QVBoxLayout>
#include <QLabel>

SwitchWindow::SwitchWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("这是新窗口", this);
    layout->addWidget(label);
    setLayout(layout);
}
void SwitchWindow::closeEvent(QCloseEvent *event)
{
    emit closed(); // 发射自定义信号，通知主窗口新窗口已关闭
    QWidget::closeEvent(event); // 调用基类的closeEvent以继续关闭窗口的默认处理
}
SwitchWindow::~SwitchWindow(){};
