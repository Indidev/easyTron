#include "Input.h"

Input::Input()
{
}

QHash<QString, QString> Input::loadMap(QString filepath)
{
    QHash<QString, QString> hashList;
    //itterate through all lines
    for (QString line: loadLines(filepath)) {
        if (!line.trimmed().isEmpty()) {
            //split on doublepoint
            QStringList splitted = line.split(":");

            //append on list, keep second part empty if not present
            hashList.insert(splitted[0].trimmed(),
                            splitted.length() > 1? splitted[1].trimmed():"");
        }
    }

    return hashList;
}

QStringList Input::loadLines(QString filepath)
{
    QStringList list;

    QFile file(filepath);
    if (file.exists()) {
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        QTextStream stream(&file);
        while (!stream.atEnd()) {
            list.append(stream.readLine());
        }
    }

    return list;
}
