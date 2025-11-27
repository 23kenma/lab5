#include <iostream>
#include <cmath>
#include<locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n, m;
    cout << "Введите количество строк N: ";
    cin >> n;
    cout << "Введите количество столбцов M: ";
    cin >> m;
    if (n <= 1 || m <= 1) {
        cout << "Матрица должна быть минимум 2x2!" << endl;
        return 1;
    }
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
    }
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nИсходная матрица " << n << "x" << m << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    int maxRow = 0, maxCol = 0;
    double maxAbsValue = fabs(matrix[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double currentAbs = fabs(matrix[i][j]);
            if (currentAbs > maxAbsValue) {
                maxAbsValue = currentAbs;
                maxRow = i;
                maxCol = j;
            }
        }
    }
    double** newMatrix = new double* [n - 1];
    for (int i = 0; i < n - 1; i++) {
        newMatrix[i] = new double[m - 1];
    }
    int newI = 0;
    for (int i = 0; i < n; i++) {
        if (i == maxRow) continue;

        int newJ = 0;
        for (int j = 0; j < m; j++) {
            if (j == maxCol) continue;

            newMatrix[newI][newJ] = matrix[i][j];
            newJ++;
        }
        newI++;
    }
    cout << "\nНовая матрица " << (n - 1) << "x" << (m - 1) << ":" << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << newMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n - 1; i++) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;

    return 0;
}