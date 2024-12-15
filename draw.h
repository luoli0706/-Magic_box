#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include<QPixmap>
#include <random>
#include <vector>
#include <iomanip>
#include<QTime>
#include<algorithm>
#include<QThread>

namespace Ui {
class Draw;
}

class Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = nullptr);
    ~Draw();
    QPixmap* random(QVector<QPixmap*>& q);
signals:
    void quitr();
    void st();
private slots:
    void on_pushButton_2_clicked();
    void to_back();
    void on_pushButton_clicked();
    void to_draw();
    void to_clear();

    void wait();
private:
    Ui::Draw *ui;
    QPixmap *pixmap=new QPixmap(":/new/prefix1/pic/Su7.png");
    QPixmap *pixmap2=new QPixmap(":/new/prefix1/pic/iphone_16promax.png");
    QPixmap *pixmap3=new QPixmap(":/new/prefix1/pic/RedmiK80.png");
    QPixmap *pixmap4=new QPixmap(":/new/prefix1/pic/joinfree.png");
};

#endif // DRAW_H
