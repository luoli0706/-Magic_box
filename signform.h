#ifndef SIGNFORM_H
#define SIGNFORM_H

#include <QWidget>
#include"draw.h"
#include<QFile>
#include"dialog_signform.h"
namespace Ui {
class SignForm;
}

class SignForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignForm(QWidget *parent = nullptr);
    ~SignForm();
signals:
    void form_appear();
    void quitr();
    void re_to(const QString& num,const QString &phone);
public slots:
    void to_re();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void to_back();

    void goshow();

    void validateInput();

private:
    Ui::SignForm *ui;
    Draw * draw=new Draw;
    Dialog_signform* ds=new Dialog_signform;
};

#endif // SIGNFORM_H
