#include "show.h"

Show::Show(QMainWindow* mainWindow)
{
    mainWIndowPtr=mainWindow;
}


void Show::showClassdata(QString tabName, QVector<QVector<QString>> classData){
    //将读到的数据按行存储到tableWidget中，每行数据存储到tableWidget的每列
    int numRows=classData.size();
    int numCols=classData[0].size();
    qDebug()<<"numRows: "<<numRows;
    qDebug()<<"numCols: "<<numCols;
    tabWidget = mainWIndowPtr->findChild<QTableWidget*>(tabName);

    qDebug()<<"tabWidget 以读取......";
    tabWidget->setColumnCount(numRows);
    tabWidget->setRowCount(numCols);
    qDebug()<<"numRows: "<<numRows;
    qDebug()<<"numCols: "<<numCols;

    for(int i=0; i<numRows; ++i){

        for(int j=0; j<numCols; ++j){
            QString value=classData[i][j];
            QTableWidgetItem *item = new QTableWidgetItem(value);
            tabWidget->setItem(j, i, item);
        }
    }

}
