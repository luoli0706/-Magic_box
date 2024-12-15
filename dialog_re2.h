#ifndef DIALOG_RE2_H
#define DIALOG_RE2_H

#include <QDialog>

namespace Ui {
class Dialog_re2;
}

class Dialog_re2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_re2(QWidget *parent = nullptr);
    ~Dialog_re2();
public slots:
    void ac(const QString&s1,const QString&s2);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_re2 *ui;
};

#endif // DIALOG_RE2_H
