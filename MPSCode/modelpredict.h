#ifndef MODELPREDICT_H
#define MODELPREDICT_H
#include<QVector>
#include<QProcess>
#include<QDebug>
#include "pretreatment.h"

#include "C:\Users\LENOVO\AppData\Local\Programs\Python\Python38\include\Python.h"
#include "D:\study\qtStu\build-MPS-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\debug\packages\include\arrayobject.h"

class ModelPredict
{
public:

    PyObject* pModule;
    PyObject* pFunc;
    PyObject* pyData;
    PyObject* pyInnerList;
    PyObject* pyValue;
    PyObject* pySecondParam;
    PyObject* args;
    PyObject *pResult;
    PyObject* pItem;

    ModelPredict();
    QVector<QString> runModel(QVector<QVector<QString>> data, QString path, const char* pyName, const char* funcName);
    void destroyPyObject();
private:

};

#endif // MODELPREDICT_H
