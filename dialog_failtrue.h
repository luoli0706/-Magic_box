#ifndef DIALOG_FAILTRUE_H
#define DIALOG_FAILTRUE_H

#include <QDialog>

namespace Ui {
class Dialog_failtrue;
}

class Dialog_failtrue : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_failtrue(QWidget *parent = nullptr);
    ~Dialog_failtrue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_failtrue *ui;
};

#endif // DIALOG_FAILTRUE_H
