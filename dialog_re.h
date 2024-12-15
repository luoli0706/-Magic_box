#ifndef DIALOG_RE_H
#define DIALOG_RE_H

#include <QDialog>

namespace Ui {
class Dialog_re;
}

class Dialog_re : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_re(QWidget *parent = nullptr);
    ~Dialog_re();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_re *ui;
};

#endif // DIALOG_RE_H
