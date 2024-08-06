#pragma once
#include <QObject>

using namespace std;

using MatrixStd = vector<vector<int>>;
using MatrixQt = QVector<QVector<int>>;
class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);
    MatrixStd multiplyMatricesQt(const MatrixStd& matrix1, const MatrixStd& matrix2);
    MatrixQt multiplyMatricesQt(const MatrixQt& matrix1, const MatrixQt& matrix2);
    MatrixQt convertToQVector(const MatrixStd& matrix);
    MatrixStd convertToStdVector(const MatrixQt& matrix);
signals:

};
