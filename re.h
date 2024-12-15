#ifndef RE_H
#define RE_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "dialog_re.h"
#include"dialog_re2.h"

namespace Ui {
class Re;
}

class Re : public QWidget
{
    Q_OBJECT

public:
    explicit Re(QWidget *parent = nullptr);
    ~Re();
signals:
    void quitr();
    void gift(const QString&s1,const QString&s2);
public slots:
    void load_to_list(const QString&num,const QString&phone);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void to_back();

    void saveBoxNumbers();

    void on_pushButton_3_clicked();

    void Re_find();

    void to_next();

private:
    Ui::Re *ui;
    QFile *file=new QFile("../../doc/box_numbers.txt");
    QVector<QString> nums;
    QVector<QString> phones;
    Dialog_re *dr1=new Dialog_re;
    Dialog_re2 *dr2=new Dialog_re2;
    QFile *file2=new QFile("../../doc/box_wait_to_re.txt");
};

#endif // RE_H
