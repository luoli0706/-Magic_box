#ifndef SWITCHWINDOW_H
#define SWITCHWINDOW_H


#include<QWidget>
class SwitchWindow : public QWidget
{
    Q_OBJECT
signals:
    void closed();
public:
    explicit SwitchWindow(QWidget *parent = nullptr);
    ~SwitchWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // SWITCHWINDOW_H
