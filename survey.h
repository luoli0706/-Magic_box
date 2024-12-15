#ifndef SURVEY_H
#define SURVEY_H

#include <QWidget>

namespace Ui {
class Survey;
}

class Survey : public QWidget
{
    Q_OBJECT

public:
    explicit Survey(QWidget *parent = nullptr);
    ~Survey();
signals:
    void quitr();
private slots:
    void on_pushButton_4_clicked();
    void to_back();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void a1();
    void a2();
    void a3();

private:
    Ui::Survey *ui;
    qint64 cn3=0;
    qint64 cn2=0;
    qint64 cn1=0;
    qint64 sum=0;
    double qcn1=0;
};

#endif // SURVEY_H
