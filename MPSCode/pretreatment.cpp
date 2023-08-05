#include "pretreatment.h"


Pretreatment::Pretreatment()
{

}

// Convert vector<double> to QVector<QString>
QVector<QString> Pretreatment::VectorToQVector(const vector<double>& vector) {
    QVector<QString> result;
    result.reserve(vector.size());
    for (double value : vector) {
        result.push_back(QString::number(value));
    }

    return result;
}
// Convert vector<vector<double>> to QVector<QVector<QString>>
QVector<QVector<QString>>Pretreatment:: VectorsToQVectors(const vector<vector<double>>& vector2D) {
    QVector<QVector<QString>> result;
    result.reserve(vector2D.size());
    for (const vector<double>& vector : vector2D) {
        result.push_back(VectorToQVector(vector));
    }
    return result;
}

// Convert QVector<QString> to vector<double>
vector<double> Pretreatment:: QVectorToVector(const QVector<QString>& qVector) {
    vector<double> result;
    result.reserve(qVector.size());

    for (const QString& str : qVector) {
        result.push_back(str.toDouble());
    }

    return result;
}

// Convert QVector<QVector<QString>> to vector<vector<double>>
vector<vector<double>> Pretreatment:: QVectorsToVectors(const QVector<QVector<QString>>& qVector2D) {
    vector<vector<double>> result;
    result.reserve(qVector2D.size());

    for (const QVector<QString>& qVector : qVector2D) {
        result.push_back(QVectorToVector(qVector));
    }

    return result;
}

QVector<QVector<QString>> Pretreatment:: traverseMatrix(const QVector<QVector<QString>>& matrix){
    int rows = matrix.size();
    int cols = (rows > 0) ? matrix[0].size() : 0;

    QVector<QVector<QString>> result(cols, QVector<QString>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Function to calculate mean of a QVector
vector<double>  Pretreatment::meanSpectrum(const vector<vector<double>>& spectra) {
    int n_samples = spectra.size();
    int n_features = spectra[0].size();

    vector<double> mean_spectrum(n_features, 0.0);

    // Calculate the sum of each feature (column)
    for (int j = 0; j < n_features; j++) {
        double sum = 0.0;
        for (int i = 0; i < n_samples; i++) {
            sum += spectra[i][j];
        }
        mean_spectrum[j] = sum / n_samples;
    }

    return mean_spectrum;
}

vector<double> Pretreatment::meanSample(const vector<vector<double>>& matrix) {
    int n_samples = matrix.size();    // Number of rows
    int n_features = matrix[0].size(); // Number of columns

    vector<double> mean(n_samples, 0.0);

    for (int i = 0; i < n_samples; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n_features; ++j) {
            sum += matrix[i][j];
        }
        mean[i] = sum / n_features;
    }


    return mean;
}

vector<double> Pretreatment::calculateStdTraverse(const vector<vector<double>>& matrix, const vector<double>& mean){
    int n_samples = matrix.size();
    int n_features = matrix[0].size();
    vector<double> result(n_features, 0.0);
    for(int j=0; j<n_features; ++j){
        double temp = 0.0;
        for(int i=0; i<n_samples; ++i){
            double diff=0.0;
            diff=matrix[i][j]-mean[j];
            temp += diff * diff;
        }
        result[j] = sqrt(temp / (n_features - 1));
    }
    return result;
}
vector<double> Pretreatment::calculateStd(const vector<vector<double>>& matrix, const vector<double>& mean){
    int n_samples = matrix.size();
    int n_features = matrix[0].size();
    vector<double> result(n_samples, 0.0);
    for(int i=0; i<n_samples; ++i){
        double temp = 0.0;
        for(int j=0; j<n_features; ++j){
            double diff=0.0;
            diff=matrix[i][j]-mean[i];
            temp += diff * diff;
        }
        result[i] = sqrt(temp / (n_features - 1));
    }
    return result;
}


// Function to calculate linear regression coefficients (k and b)
void Pretreatment::linearRegression(const vector<double>& x, const vector<double>& y, double& k, double& b) {
    if(x.size()!=y.size()){
        throw invalid_argument("Input matrix formats do not match.");
    }
    double sumX = 0.0;
        double sumY = 0.0;
        int columnCount = x.size();

        for (int j = 0; j < columnCount; j++) {
            sumX += x[j];
            sumY += y[j];
        }

        double meanX = sumX / columnCount;
        double meanY = sumY / columnCount;

        double tempXY = 0;
        double tempX = 0;
        double tempY = 0;

        for (int j = 0; j < columnCount; j++) {
            tempXY += (x[j] - meanX) * (y[j] - meanY);
            tempX += pow((x[j] - meanX), 2);
            tempY += pow((y[j] - meanY), 2);
        }

        k = tempXY/tempX;
        b = meanY- (k*meanX);


}


QVector<QVector<QString>> Pretreatment:: msc(const QVector<QVector<QString>>& data) {
    QVector<QVector<QString>> spec_msc;
    vector<vector<double>> sdata=QVectorsToVectors(data);

    //calcu_spec.reserve(sdata.size());

    int m = sdata.size(); // 样本数量
    int n=sdata[0].size();
    std::vector<double> k(m, 0.0);
    std::vector<double> b(m, 0.0);

    std::vector<double> M;

    vector<vector<double>> calcu_spec;
    calcu_spec.reserve(m);
    qDebug()<<"sdata row size: "<<sdata.size();
    qDebug()<<"sdata col size: "<<sdata[0].size();

    for (int i = 0; i < m; ++i) {
        vector<double> y = sdata[i];
        M= meanSpectrum(sdata); // sdata col size
        linearRegression(M, y, k[i], b[i]);
        vector<double>cols_res;
        double res=0.0;
        for (int j = 0; j < n; ++j) {
            res = (sdata[i][j] - b[i]) / k[i];
            cols_res.push_back(res);
        }
        calcu_spec.push_back(cols_res);
    }
    spec_msc=VectorsToQVectors(calcu_spec);
    return spec_msc;

}


QVector<QVector<QString>> Pretreatment:: snv(const QVector<QVector<QString>>& sdata){
    QVector<QVector<QString>> spec_msc;
    vector<vector<double>> Ynir=QVectorsToVectors(sdata);
    int m = Ynir.size();    // Number of samples(rows)
    int n = Ynir[0].size(); // Number of features(cols)
    vector<double> row_mean=meanSample(Ynir);
    vector<double>row_stdev=calculateStd(Ynir, row_mean);

//    qDebug()<<"Ynir row size:"<<m;
//    qDebug()<<"Ynir col size:"<<n;
//    qDebug()<<"row_mean row size:"<<row_mean.size();
//    qDebug()<<"row_stdev row size:"<<row_stdev.size();

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            double res=(Ynir[i][j]-row_mean[i])/row_stdev[i];
            Ynir[i][j]=res;
        }
    }


//    qDebug()<<"result row size:"<<result.size();
//    qDebug()<<"result col size:"<<result[0].size();

    spec_msc=VectorsToQVectors(Ynir);
//    qDebug()<<"spec_msc row size:"<<spec_msc.size();
//    qDebug()<<"spec_msc col size:"<<spec_msc[0].size();
    return spec_msc;
}


const QVector<QVector<QString>> Pretreatment::  calculateFirstDerivative(const QVector<QVector<QString>>& sdata) {

    QVector<QVector<QString>> spec_msc;
    vector<vector<double>> data=QVectorsToVectors(sdata);
    int n = data.size();    // Number of samples
    int p = data[0].size(); // Number of features

    vector<vector<double>> Di(n, vector<double>(p - 10, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p - 10; ++j) {
            Di[i][j] = data[i][j + 10] - data[i][j];
        }
    }

    return VectorsToQVectors(Di);
}

const QVector<QVector<QString>> Pretreatment::  calculateSecondDerivative(const QVector<QVector<QString>>& sdata) {

//    QVector<QVector<QString>> spec_msc;
//    vector<vector<double>> data=QVectorsToVectors(sdata);
//    int n = data.size();    // Number of samples
//    int p = data[0].size(); // Number of features

    QVector<QVector<QString>> Di = calculateFirstDerivative(sdata);
    QVector<QVector<QString>> D2 = calculateFirstDerivative(Di);
    return D2;


}


QVector<QVector<QString>> Pretreatment:: standardize(const QVector<QVector<QString>>& data){
    QVector<QVector<QString>> spec_msc;
    vector<vector<double>> Ynir=QVectorsToVectors(data);
    int m = Ynir.size();    // Number of samples(rows)
    int n = Ynir[0].size(); // Number of features(cols)
    vector<double> col_mean=meanSpectrum(Ynir);
    qDebug()<<"col_mean row size:"<<col_mean.size();
    vector<double>col_stdev=calculateStdTraverse(Ynir, col_mean);
    qDebug()<<"Ynir row size:"<<m;
    qDebug()<<"Ynir col size:"<<n;

    qDebug()<<"col_stdev row size:"<<col_stdev.size();

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            double res=(Ynir[i][j]-col_mean[j])/col_stdev[j];
            Ynir[i][j]=res;
        }
    }
    spec_msc=VectorsToQVectors(Ynir);
    return spec_msc;
}

vector<vector<double>> Pretreatment:: calculateAugment(const vector<vector<double>>& x,
                                                          double betashift = 0.05,
                                                          double slopeshift = 0.05,
                                                          double multishift = 0.05) {
     int numRows = x.size();
     int numCols = x[0].size();

     // 定义随机数生成器
     random_device rd;
     mt19937 gen(rd());
     uniform_real_distribution<double> dist(-betashift, betashift);
     uniform_real_distribution<double> slopeDist(1.0 - slopeshift, 1.0 + slopeshift);
     uniform_real_distribution<double> multiDist(1.0 - multishift, 1.0 + multishift);

     // 生成随机数数组
     vector<vector<double>> beta(numRows, vector<double>(1));
     vector<vector<double>> slope(numRows, vector<double>(1));
     vector<vector<double>> multi(numRows, vector<double>(1));
     for (int i = 0; i < numRows; ++i) {
         beta[i][0] = dist(gen);
         slope[i][0] = slopeDist(gen);
         multi[i][0] = multiDist(gen);
     }

     // 计算相对位置
     vector<double> axis(numCols);
     for (int i = 0; i < numCols; ++i) {
         axis[i] = static_cast<double>(i) / numCols;
     }

     // 计算偏移量
     vector<vector<double>> offset(numRows, vector<double>(numCols));
     for (int i = 0; i < numRows; ++i) {
         for (int j = 0; j < numCols; ++j) {
             offset[i][j] = slope[i][0] * axis[j] + beta[i][0] - axis[j] - slope[i][0] / 2. + 0.5;
         }
     }

     // 数据增强
     vector<vector<double>> augmentedData(numRows, vector<double>(numCols));
     for (int i = 0; i < numRows; ++i) {
         for (int j = 0; j < numCols; ++j) {
             augmentedData[i][j] = multi[i][0] * x[i][j] + offset[i][j];
         }
     }

     return augmentedData;
 }

QVector<QVector<QString>> Pretreatment:: getAugment(const QVector<QVector<QString>>& data)
{
    vector<vector<double>> Ynir=QVectorsToVectors(data);
    int m = Ynir.size();    // Number of samples(rows)
    int n = Ynir[0].size(); // Number of features(cols)
    vector<vector<double>> newNir;
    for (const vector<double>& qVector : Ynir) {
        for(int i=0; i<5; ++i){
            newNir.push_back(qVector);
        }
    }
    qDebug()<<"newNir row shape: "<<newNir.size();
    qDebug()<<"newNir col shape: "<<newNir[0].size();
    newNir=calculateAugment(newNir);
    return VectorsToQVectors(newNir);

}



