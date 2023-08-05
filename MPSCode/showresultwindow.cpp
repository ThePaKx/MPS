#include "showresultwindow.h"
#include "show.h"

ShowResultWindow::ShowResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowResultWindow)
{
    ui->setupUi(this);
    showData();

}

ShowResultWindow::~ShowResultWindow()
{
    delete ui;
}

void ShowResultWindow::showData()
{
    qDebug()<<"show  result: "<<result;
}

void ShowResultWindow::processData(QStringList lists, QVector<QString> preLists)
{
    qDebug()<<"lists: "<<lists;
    QVector<QString> pathes = lists.toVector();
    qDebug()<<"processData pathes: "<<lists;
    result.push_back(pathes);
    result.push_back(preLists);
//    qDebug()<<"result size: "<<result.size();
//    qDebug()<<"result: "<<result;
    Show(this).showClassdata("preresWidget", result);

}






