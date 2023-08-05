#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCharts>
#include<QChartView>
#include<QSplineSeries>
#include<QLineSeries>
#include<QPushButton>
#include<QFileDialog>
#include<QAxObject>
#include<QList>
#include<QDebug>
#include<QMessageBox>
#include<QCloseEvent>
#include "pretreatment.h"
#include "modelpredict.h"
#include<QDir>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include<QTabWidget>
#include "show.h"
#include "savedata.h"
#include "C:\Users\LENOVO\AppData\Local\Programs\Python\Python38\include\Python.h"
#include "showresultwindow.h"

QT_BEGIN_NAMESPACE


namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList specPathes;

    QVector<QVector<QString>> exc_res;
    QVector<QVector<QString>> class_res;
    QVector<QString> predict_res;
    int intRows;
    int intCols;
    QString modelFilePath;


    void getExcelContent(QVector<QVector<QString>>& result, QStringList filePathes);
    void getCsvContent(QVector<QVector<QString>>& result, QStringList filePathes);
    void showSpec(QVector<QVector<QString>> spectro);
    //void showClassdata(QVector<QVector<QString>> classData);
    void closeEvent(QCloseEvent *e);
private slots:
    void on_actionsave_triggered();

private:
    Ui::MainWindow *ui;
    QChart *mChart;
    QAxObject *excel;
    QAxObject *workbooks;
    QAxObject *workbook;
    QStringList filePathes;




};
#endif // MAINWINDOW_H
