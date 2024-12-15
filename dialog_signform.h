#ifndef DIALOG_SIGNFORM_H
#define DIALOG_SIGNFORM_H

#include <QDialog>

namespace Ui {
class Dialog_signform;
}

class Dialog_signform : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_signform(QWidget *parent = nullptr);
    ~Dialog_signform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_signform *ui;
};

#endif // DIALOG_SIGNFORM_H
