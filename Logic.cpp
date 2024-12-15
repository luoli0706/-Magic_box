#include"Logic.h"
CrewMemberList::CrewMemberList(const QString &filePath) {
    QFile *file=new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << filePath;
        return;
    }

    QTextStream in(file);
    QString line;
    int lineNumber = 0;
    while (!in.atEnd()) {
        line = in.readLine().trimmed();
        lineNumber++;
        if (lineNumber % 2 == 1) {
            ids.append(line);
        } else {
            passwords.append(line);
        }
    }

    file->close();
}
bool CrewMemberList::verify(const QString &id, const QString &password) const {
    for (int i = 0; i < ids.size(); ++i) {
        if (ids[i] == id && passwords[i] == password) {
            return true;
        }
    }
    return false; // 如果没有找到匹配的ID和密码对，则返回false
}
void CrewMemberList::print(){
    for(auto i:ids)
        qDebug()<<i;
}
