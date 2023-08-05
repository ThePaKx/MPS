#ifndef SHOWRESULTWINDOW_H
#define SHOWRESULTWINDOW_H

#include "ui_showresultwindow.h"
#include "show.h"
#include "mainwindow.h"

namespace Ui {

class MainWindow;

class ShowResultWindow;
}

class ShowResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowResultWindow(QWidget *parent = nullptr);
    ~ShowResultWindow(); 
    QVector<QVector<QString>> result;
    void showData();
    void processData(QStringList lists, QVector<QString> preLists);

private:

    Ui::ShowResultWindow *ui;

};

#endif // SHOWRESULTWINDOW_H
