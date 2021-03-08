#include <iostream>
#include <iomanip>

using namespace std;

void printMatrix(float (&m)[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(5) << m[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

int main() {
    float matrix[3][4] = { {2, 1, -3, -5}, {-3, 4, 1, 6}, {-1, 2, -3, -4} };
    printMatrix(matrix);

    cout.precision(2);

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            float coefficient = matrix[j][i] / matrix[i][i];
            for (int k = i; k < 4; k++)
                matrix[j][k] -= matrix[i][k] * coefficient;
            cout << endl;
        }
	printMatrix(matrix);
    }

    for (int i = 2; i >= 0; i--) { 
        for (int j = 2; j > i; j--) {
            matrix[i][3] -= matrix[i][j] * matrix[j][3];
         	cout << endl;   
        }
        matrix[i][3] /= matrix[i][i];
		printMatrix(matrix);
    }
    
    for (int i = 0; i < 3; i++) {
        cout << "X [" << i << "] = " << matrix[i][3] << " ";
        cout << endl;
    }
    cout << endl;
}