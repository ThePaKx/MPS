#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <iostream>
#include <QVector>
#include <QString>
#include <QTextStream>
#include<cmath>
#include<QDebug>
#include<random>

using namespace std;
class Pretreatment
{
public:
    Pretreatment();
    vector<double> meanSpectrum(const vector<vector<double>>& data) ;
    vector<double> meanSample(const vector<vector<double>>& matrix);
    vector<double> calculateStd(const vector<vector<double>>& matrix, const vector<double>& mean);
    vector<double> calculateStdTraverse(const vector<vector<double>>& matrix, const vector<double>& mean);
    void linearRegression(const vector<double>& x, const vector<double>& y, double& k, double& b);
    QVector<QVector<QString>> msc(const QVector<QVector<QString>>& sdata);
    QVector<QVector<QString>> snv(const QVector<QVector<QString>>& sdata);
    QVector<QString> VectorToQVector(const vector<double>& vector) ;
    QVector<QVector<QString>> VectorsToQVectors(const vector<vector<double>>& vector2D) ;
    vector<double> QVectorToVector(const QVector<QString>& qVector);
    vector<vector<double>> QVectorsToVectors(const QVector<QVector<QString>>& qVector2D);
    QVector<QVector<QString>> traverseMatrix(const QVector<QVector<QString>>& data);
    const QVector<QVector<QString>> calculateFirstDerivative(const QVector<QVector<QString>>& data) ;
    const QVector<QVector<QString>> calculateSecondDerivative(const QVector<QVector<QString>>& data) ;

    QVector<QVector<QString>> standardize(const QVector<QVector<QString>>& data);
    vector<vector<double>> calculateAugment(const vector<vector<double>>& x, double betashift,double slopeshift, double multishift);
    QVector<QVector<QString>> getAugment(const QVector<QVector<QString>>& data);

};

#endif // PRETREATMENT_H
