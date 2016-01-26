#ifndef INPUT_H
#define INPUT_H

#include <QHash>
#include <QString>
#include <QFile>
#include <QTextStream>

class Input
{
public:
    static QHash<QString, QString> loadMap(QString filepath);
    static QStringList loadLines(QString filepath);

private:
    Input();

};

#endif // INPUT_H
