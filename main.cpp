#include <QCoreApplication>
#include "calculator.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MatrixStd stdMatrix1 = {{1, 2}, {3, 4}};
    MatrixStd stdMatrix2 = {{5, 6}, {7, 8}};
    Calculator cal;
    MatrixStd resultStd = cal.multiplyMatricesQt(stdMatrix1, stdMatrix2);

    // Display the result
    for (const auto& row : resultStd) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    return a.exec();
}
