#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QMainWindow>
#include<QTimer>
#include"signform.h"
#include"re.h"
#include"survey.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void quitr();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void to_back();

    void goshow();

private:
    Ui::Form *ui;
    Re * re=new Re;
    Survey * survey=new Survey;
    SignForm * sf=new SignForm;
    void Init();
};

#endif // FORM_H
