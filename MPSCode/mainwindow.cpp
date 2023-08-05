#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ModelPredict().runModel2();
    connect(ui->openSpec, &QAction::triggered,[=](){
        ShowResultWindow showResultWindow;
        specPathes = QFileDialog::getOpenFileNames(
                    this, tr("Open File"),"",
                    tr("CSV files (*.csv);;Excel files(*.xls *.xlsx)"));
        if(specPathes.isEmpty()){
            QMessageBox::warning(this, "Warning!", "Failed to open Files!");
        }
        else{
            exc_res.clear();
            //样本：(n_features, n_samples)
            QFileInfo fileinfo=QFileInfo(specPathes[0]);
            if(fileinfo.suffix()=="xlsx"||fileinfo.suffix()=="xls")
                getExcelContent(exc_res, specPathes);//exc_res中数据即为excel内容
            else if(fileinfo.suffix()=="csv")
                getCsvContent(exc_res, specPathes);
            if(!exc_res.isEmpty()){
                showSpec(exc_res);
            }
            else{
                QMessageBox::warning(this, "Warning!", "exc_res is empty!");
            }
        }
    });
    connect(ui->openReal, &QAction::triggered,[=](){

        filePathes = QFileDialog::getOpenFileNames(
                    this, tr("Open File"),"",
                    tr("Excel files(*.xls *.xlsx);;CSV files (*.csv)"));
        if(filePathes.isEmpty()){
            QMessageBox::warning(this, "Warning!", "Failed to open Files!");
        }
        else{
            class_res.clear();
            //样本：(n_features, n_samples)
            QFileInfo fileinfo=QFileInfo(filePathes[0]);
            if(fileinfo.suffix()=="xlsx"||fileinfo.suffix()=="xls")
                getExcelContent(class_res, filePathes);//exc_res中数据即为excel内容
            else if(fileinfo.suffix()=="csv")
                getCsvContent(class_res, filePathes);
            if(!class_res.isEmpty()){
                qDebug()<<"class_res row shape: "<<class_res.size();
                qDebug()<<"class_res col shape: "<<class_res[0].size();
                if(class_res.size()>2){QMessageBox::warning(this, "Warning!", "Wrong input data shape!");}
                if(class_res.size()==2){
                    QVector<QString> temp = class_res[1];
                    class_res.clear();
                    class_res.append(temp);
                }
                qDebug()<<"class_res: "<<class_res;
                Show(this).showClassdata("showCTableWidget", class_res);

            }
            else{
                QMessageBox::warning(this, "Warning!", "class_res is empty!");
            }
        }
    });
    connect(ui->actionMSC, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
            QVector<QVector<QString>> msc_res = Pretreatment().msc(exc_res);
            exc_res.reserve(msc_res.size());
            exc_res=msc_res;
            showSpec(exc_res);
        }
    });
    connect(ui->actionSNV, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
            QVector<QVector<QString>> snv_res = Pretreatment().snv(exc_res);
            exc_res.reserve(snv_res.size());
            exc_res=snv_res;
            showSpec(exc_res);
        }
    });
    connect(ui->actionFD, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
             QVector<QVector<QString>> fd_res = Pretreatment().calculateFirstDerivative(exc_res);
             exc_res.reserve(fd_res.size());
             exc_res=fd_res;
            showSpec(exc_res);
        }
    });
    connect(ui->actionSD, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
             QVector<QVector<QString>> sd_res = Pretreatment().calculateSecondDerivative(exc_res);
             exc_res.reserve(sd_res.size());
             exc_res=sd_res;
            showSpec(exc_res);
        }
    });
    connect(ui->actionNormalize, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
             QVector<QVector<QString>> sd_res = Pretreatment().standardize(exc_res);
             exc_res.reserve(sd_res.size());
             exc_res=sd_res;
            showSpec(exc_res);
        }
    });
    connect(ui->actionAUG, &QAction::triggered, [=](){
        if(!exc_res.isEmpty()){
             QVector<QVector<QString>> sd_res = Pretreatment().getAugment(exc_res);
             exc_res.reserve(sd_res.size());
             exc_res=sd_res;
            showSpec(exc_res);
        }
    });

    connect(ui->actionloadSVCModel, &QAction::triggered, [=](){
        ModelPredict MP;
        modelFilePath = QFileDialog::getOpenFileName(
                    this, tr("Open File"),"",
                    tr("joblib files (*.joblib);;h5 files(*.h5)"));
        predict_res = MP.runModel(exc_res, modelFilePath, "loadModel", "predict");
        qDebug()<<"predict_res: "<<predict_res;
        qDebug()<<"ui specPathes: "<<specPathes;
        ShowResultWindow* showResultWindow = new ShowResultWindow(this);
        showResultWindow->processData(specPathes, predict_res);

        showResultWindow->show();


    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getExcelContent(QVector<QVector<QString>> &result, QStringList filePathes)
{

    excel = NULL;
    workbooks = NULL;
    workbook = NULL;

    foreach (const QString &filePath, filePathes) {
        CoInitializeEx(NULL, COINIT_MULTITHREADED);
        excel = new QAxObject("Excel.Application");
        if(!excel)
        {
            qDebug()<<"EXCEL 对象丢失！";
        }
        workbooks = excel->querySubObject("Workbooks");//所有excel文件
        if(0==workbooks)
        {
            qDebug()<<"Kong000000000";
            return;
        }
        workbook = workbooks->querySubObject("Open (const QString &)",filePath);//按路径获取文件
        if(0==workbook)
        {
            qDebug()<<"workbook000000000";
            return;
        }
        QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 1);//读取第一个表

        QAxObject *usedRange = worksheet->querySubObject("UsedRange");//有数据的矩形区域
        QAxObject * rows = usedRange->querySubObject("Rows");
        QAxObject * columns = usedRange->querySubObject("Columns");
        int Rows = rows->property("Count").toInt();
        int Cols = columns->property("Count").toInt();

        for(int i=1;i<=Cols; ++i){
            QVector<QString> vecDataRow;
            for(int j=1;j<=Rows;++j){
                QString txt = worksheet->querySubObject("Cells(int,int)", j,i)->dynamicCall("Value").toString(); //获取单元格内容
                vecDataRow.append(txt);

            }
            result.push_back(vecDataRow);

        }

        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        if(excel)
        {
            delete excel;
            excel = NULL;
        }
    }

}

void MainWindow::getCsvContent(QVector<QVector<QString>> &result, QStringList filePathes){
     //QVector<QVector<QString>>data;
    //filePathes = QFileDialog::getOpenFileNames(nullptr, "打开CSV文件", "", "CSV files (*.csv)");
    foreach(QString filePath, filePathes){
        if (filePath.isEmpty()) {
            qDebug() << "No file selected.";
            return;
        }

        // 打开CSV文件
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Error opening the file:" << file.errorString();
            return;
        }
        QTextStream in(&file);
        QVector<QString> row;
        QVector<QString> col;
        // 读取文件内容
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(","); // 根据CSV文件中的分隔符进行拆分
            if(fields.size()==2)
                row.append(fields[1]);
            else
                row.append(fields[0]);

        }
        result.append(row);

//        QStringList tempOption = in.readAll().split("\n");
//        qDebug()<<"tempOption size: "<<tempOption.size();
//        for(int i=0; i<tempOption.count();++i){
//            QStringList tempbar = tempOption.at(i).split(",");
//            //qDebug()<<"tempbar size: "<<tempbar.size();
//            for(int j=0; j<tempbar.size(); ++j){
//                col.append(tempbar.at(j));
//            }
//            result.append(col);
//        }

        // 关闭文件
        file.close();
    }

}

void MainWindow::showSpec(QVector<QVector<QString>> spectro){
    intRows = spectro.size();
    intCols = spectro.isEmpty() ? 0 : spectro[0].size();
    mChart = new QChart();
    mChart->removeAllSeries();
    //qDebug()<<"intCols----"<<intCols;
    //qDebug()<<"intRows----"<<intRows;
    for(int j=0; j<intRows; ++j)
    {
        QSplineSeries *splineSeries = new QSplineSeries();
        for(int i=0; i<intCols; ++i)
        {
            //qDebug()<<"j="<<j<<" , i="<<i;
            splineSeries->append(i,exc_res[j][i].toDouble());
        }
        mChart->addSeries(splineSeries);
    }

    mChart->setTheme(QChart::ChartThemeLight);
    mChart->legend()->hide();
    mChart->setTitle("光谱展示");           // 设置标题
    mChart->createDefaultAxes();                // 基于已添加到图表中的series为图表创建轴。以前添加到图表中的任何轴都将被删除。
    //mChart->axes(Qt::Vertical).first()->setRange(0, 1);  // 设置Y轴的范围

    ui->widget->setRenderHint(QPainter::Antialiasing);  // 设置抗锯齿
    ui->widget->setChart(mChart);//拖入界面的控件名为widget
}


void MainWindow::closeEvent(QCloseEvent *e){
    //窗口关闭时弹出的提示窗口
    QMessageBox msgBox;
    msgBox.setText("提示");
    msgBox.setInformativeText("确认退出?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok){
        //若用户点击确认，则接收这个事件,当前窗口会关闭
        //销毁py对象
        ModelPredict().destroyPyObject();
        e->accept();
    }else{
        //若用户点击取消，则忽略这个事件，当前窗口不会关闭
        e->ignore();
    }
}



void MainWindow::on_actionsave_triggered()
{
    int row = exc_res.size();
    for(int i=0; i<row; ++i){
        QVector<QString> row_data = exc_res[i];
        SaveData* sd = new SaveData();
        QStringList standardLocation = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
        QString desktopPath = standardLocation.join("");
        desktopPath.push_back("/");
        desktopPath.push_back("spec");
        desktopPath.push_back(QString::number(i+1));
        desktopPath.push_back(".csv");
        sd->specToCSV(desktopPath, row_data);
    }
}
