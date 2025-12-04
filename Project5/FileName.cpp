#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cout << "vvedite kolvo strok and stolbtsov" << endl;
    cout << " N: ";
    cin >> n;
    cout << endl;
    cout << " M: ";
    cin >> m;
    int** mtrx = new int* [n];
    for (int i = 0; i < n; i++)
        mtrx[i] = new int[m];
    cout << "vvedite elements matritsi: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mtrx[i][j];
    double maxAbsValue = fabs(mtrx[0][0]);
    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double currentAbs = fabs(mtrx[i][j]);
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
    int newRow = 0;
    for (int i = 0; i < n; i++) {
        if (i == maxRow) continue; 
        int newCol = 0;
        for (int j = 0; j < m; j++) {
            if (j == maxCol) continue; 
            newMatrix[newRow][newCol] = mtrx[i][j];
            newCol++;
        }
        newRow++;
    }
    cout << "\nnewmatrix " << (n - 1) << "x" << (m - 1) << ":" << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        delete[] mtrx[i];
    delete[] mtrx;
    return 0;
}
