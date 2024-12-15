#ifndef WAITWIDGE_H
#define WAITWIDGE_H

#include <QWidget>
#include <QPaintEvent>

// WaitWidge 类继承自 QWidget，用于显示等待动画
class WaitWidge : public QWidget
{
    Q_OBJECT

public:
    WaitWidge(QWidget *parent = nullptr);
    ~WaitWidge();

protected:
    // 重载 paintEvent 方法，用于自定义绘制
    void paintEvent(QPaintEvent *) override;

private:
    QPixmap* m_pPixmap; // 用于储存等待动画图片
    QTimer* m_pTimer;   // 用于更新动画
};

#endif // WAITWIDGE_H

