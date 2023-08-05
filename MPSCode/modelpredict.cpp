#include "modelpredict.h"

ModelPredict::ModelPredict()
{

}
QVector<QString> ModelPredict::runModel(QVector<QVector<QString>> data, QString path, const char* pyName, const char* funcName){

    Py_SetPythonHome((const wchar_t *)(L"C:/Users/LENOVO/AppData/Local/Programs/Python/Python38"));
    if(!Py_IsInitialized())
    {
        qDebug()<<"初始化py";
        Py_Initialize();
    }
    if( !Py_IsInitialized() )
        qDebug()<<"初始化失败";
    //导入sys模块设置模块地址
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    qDebug()<<"path: "<<path;
    qDebug()<<"data row size: "<<data.size();
    qDebug()<<"data col size: "<<data[0].size();

    //创建模块指针
    pModule = PyImport_ImportModule(pyName);
    if (!pModule)
        qDebug()<<"获取模块指针失败";
    else
        qDebug()<<"获取模块指针成功";
    //创建函数指针
    pFunc= PyObject_GetAttrString(pModule,funcName);

    if(!pFunc)
        qDebug()<<"获取函数指针失败";
    else
        qDebug()<<"获取函数指针成功";


    //转换第一个参数为Python的列表
    pyData = PyList_New(data.size());
    for(int i=0; i<data.size();++i){
        QVector<QString>innerVector = data[i];
        pyInnerList = PyList_New(innerVector.size());
        for(int j=0; j<innerVector.size(); ++j){
            QString value = innerVector[j];
            pyValue = PyUnicode_FromString(value.toUtf8().constData());
            PyList_SetItem(pyInnerList, j, pyValue);
        }
        PyList_SetItem(pyData, i, pyInnerList);
    }
    qDebug()<<"获取第一个参数成功";
    //转换第二个参数为Python的字符串
    pySecondParam = PyUnicode_FromString(path.toUtf8().constData());
    qDebug()<<"获取第一个参数成功";
    //准备参数列表
    args = PyTuple_New(2);
    PyTuple_SetItem(args, 0, pyData);
    PyTuple_SetItem(args, 1, pySecondParam);
    qDebug()<<"准备参数列表成功";
    qDebug()<<"args: "<<args;
    qDebug()<<"pFunc: "<<pFunc;
    //调用Python函数，传入元组参数pPara
    pResult = PyObject_CallObject(pFunc,args);


    if (pResult == nullptr)
        {
            // Handle the error, you can print the Python error message using PyErr_Print()
            PyErr_Print();
            // Or you can use qDebug() to log the error message
            qDebug() << "Error calling Python function.";
        }

    qDebug()<<"传入元组参数成功";

    // 将Python返回值转换为Qt的数据类型 (QVector<QVector<QString>>)
    QVector<QString> dataList;
    if (PyList_Check(pResult)) {
        qDebug()<<"PyList_Size(pResult): "<<PyList_Size(pResult);
        int listSize = PyList_Size(pResult);
//        QString qtString = QString::fromUtf8(PyUnicode_AsUTF8(pResult));
//        qDebug()<<"qtString: "<<qtString;
        for (int i = 0; i < listSize; ++i) {
            pItem = PyList_GetItem(pResult, i);
            if(PyUnicode_Check(pItem)){
                QString qtString = QString::fromUtf8(PyUnicode_AsUTF8(pItem));
                dataList.push_back(qtString);
            }else {
                qWarning() << "Element at index" << i << "is not a string.";
            }

        }
    }
    return dataList;
}


void ModelPredict::destroyPyObject()
{
    if( Py_IsInitialized() ){
        Py_Finalize();
        qDebug()<<"全部销毁";
    }

}


