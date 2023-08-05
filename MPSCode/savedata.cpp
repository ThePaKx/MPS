#include "savedata.h"

SaveData::SaveData()
{

}

bool SaveData::specToCSV(const QString& filePath, const QVector<QString>& data) {
    qDebug()<<"filePath--------------- "<<filePath;


    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return false;
    }
    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (const QString& item : data) {
        // 如果字符串中包含逗号或换行符等特殊字符，需要进行处理
        QString escapedItem = item;
        escapedItem.replace("\"", "\"\""); // 处理双引号
        if (escapedItem.contains(",") || escapedItem.contains("\n")) {
            escapedItem = "\"" + escapedItem + "\""; // 使用双引号包围字段
        }
        out << escapedItem << "\n"; //","
    }
    file.close();
    return true;
}





