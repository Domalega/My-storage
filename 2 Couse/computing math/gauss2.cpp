#include <iostream>
#include <iomanip>
#include <math.h>

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

    for (int c = 0 ; c < 2 ; c++) { 
        int max = c ;
        for (int i = c + 1 ; i < 3 ; i++)  
            if (abs(matrix[max][c]) < abs(matrix[i][c]))
                max = i;
        if (max != c) {
			swap(matrix[max],  matrix[c]);
            printMatrix(matrix); 
        }

        for (int i = c + 1; i < 3; i++) {
            float coefficient = (matrix[i][c] / matrix[c][c]) * -1;
            for (int j = c; j < 4; j++) 
                matrix[i][j] += matrix[c][j] * coefficient;
        }
        printMatrix(matrix) ;
    }


    for (int c = 2 ; c > -1; c--) {
        for (int i = 2 ; i > c; i--)
            matrix[c][3] -=  matrix[c][i];

        matrix[c][3]	/= matrix[c][c];

        for (int i = 0 ; i < c; i++)
            matrix[i][c] *= matrix[c][3];
    }
    
    cout << endl;
}