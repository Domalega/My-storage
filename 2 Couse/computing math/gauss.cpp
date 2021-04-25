#include <iostream>
#include <iomanip>

using namespace std;

const int n = 4;

void printMatrix(float (&m)[n - 1][n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(5) << m[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

int main() {
    float matrix[n - 1][n] = { {2, 1, -3, -5}, {-3, 4, 1, 6}, {-1, 2, -3, -4} };
    printMatrix(matrix);

    cout.precision(2);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            float coefficient = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
                matrix[j][k] -= matrix[i][k] * coefficient;
            cout << endl;
        }
  cout << i + 1 << " столбец занулен \n";
	printMatrix(matrix);
    }

    for (int i = n - 2; i >= 0; i--) { 
        for (int j = n - 2; j > i; j--) {
            matrix[i][n - 1] -= matrix[i][j] * matrix[j][n - 1];
         	cout << endl;   
        }
        matrix[i][n - 1] /= matrix[i][i];
		printMatrix(matrix);
    }
    
    for (int i = 0; i < n - 1; i++) {
        cout << "X [" << i << "] = " << matrix[i][n - 1] << " ";
        cout << endl;
    }
    cout << endl;
}
