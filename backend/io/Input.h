#ifndef INPUT_H
#define INPUT_H

#include "EasyTronDef.h"
#include <QHash>
#include <QString>
#include <QFile>
#include <QTextStream>

/**
 * @brief The Input class
 * class which contains functions to read from files
 */
class Input
{
public:
    /**
     * load content of a file as a map (key: value)
     * if a value is not present, the key will be saved without a value.
     * empty lines will be skipped
     * @param filepath path of the file...
     * @return key-value hashmap
     */
    static QHash<QString, QString> loadMap(QString filepath);

    /**
     * load all lines of a file
     * @param filepath path of the file...
     * @return content of file as list
     */
    static QStringList loadLines(QString filepath);

private:
    Input();

};

#endif // INPUT_H
