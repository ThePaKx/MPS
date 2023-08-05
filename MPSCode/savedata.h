#ifndef SAVEDATA_H
#define SAVEDATA_H


#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QDebug>

class SaveData
{
public:
    SaveData();
    bool specToCSV(const QString& filePath, const QVector<QString>& data);
};

#endif // SAVEDATA_H
