#ifndef LOGIC_H
#define LOGIC_H
#pragma once
#include<string>
#include<vector>
#include<QString>
#include"mainwindow.h"
#include<QFile>
#include<QDebug>
#include<QCryptographicHash>
class Logic{
public:
    Logic();
};
class CrewMemberList {
public:
    CrewMemberList(const QString &filePath);
    bool verify(const QString &id, const QString &password) const;
    void print();
private:
    QVector<QString> ids;
    QVector<QString> passwords;
};
#endif // LOGIC_H
