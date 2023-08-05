#ifndef SHOW_H
#define SHOW_H
#include "mainwindow.h"
#include "showresultwindow.h"

#include<QVector>
#include<QDebug>

class Show
{
public:
    Show(QMainWindow* mainWindow);
    void showClassdata(QString tabName, QVector<QVector<QString>> classData);
private:
    QMainWindow* mainWIndowPtr;
    QTableWidget *tabWidget;
};

#endif // SHOW_H
