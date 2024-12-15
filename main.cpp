#include "mainwindow.h"
#include "form.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "box_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow *w=new MainWindow;
    w->setStyleSheet("background-image:url(:/new/prefix1/star_sky.png)");
    w->show();
    return a.exec();
}
