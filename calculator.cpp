#include "calculator.h"
#include <iostream>
#include <vector>
#include <QVector>
#include <QDebug>

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}

MatrixStd Calculator::multiplyMatricesQt(const MatrixStd &matrix1, const MatrixStd &matrix2)
{
    // Convert matrices to MatrixQt
    MatrixQt qtMatrix1 = convertToQVector(matrix1);
    MatrixQt qtMatrix2 = convertToQVector(matrix2);

    // Perform multiplication in Qt language
    MatrixQt qtResult = multiplyMatricesQt(qtMatrix1, qtMatrix2);

    // Convert the result back to MatrixStd
    return convertToStdVector(qtResult);
}


MatrixQt Calculator::multiplyMatricesQt(const MatrixQt& matrix1, const MatrixQt& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        qWarning() << "Matrix multiplication not possible: Number of columns in the first matrix must be equal to the number of rows in the second matrix.";
        return MatrixQt();
    }

    MatrixQt result(rows1, QVector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

MatrixQt Calculator::convertToQVector(const MatrixStd& matrix) {
    MatrixQt result;
    for (const auto& row : matrix) {
        QVector<int> qRow(row.begin(), row.end());
        result.append(qRow);
    }
    return result;
}

MatrixStd Calculator::convertToStdVector(const MatrixQt& matrix) {
    MatrixStd result;
    for (const auto& qRow : matrix) {
        vector<int> row(qRow.begin(), qRow.end());
        result.push_back(row);
    }
    return result;
}
