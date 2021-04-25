#include <iostream>
#include <iomanip>
#include <math.h>

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

  for (int c = 0 ; c < n - 2 ; c++) { 
    int max = c ;
    for (int i = c + 1 ; i < n - 1 ; i++)  
      if (abs(matrix[max][c]) < abs(matrix[i][c]))
        max = i;
      if (max != c) {
			  swap(matrix[max],  matrix[c]);
        cout << "Поменяли " << c + 1 << " и " << max + 1 << " строку\n";
        printMatrix(matrix); 
      }
        
    for (int i = c + 1; i < n - 1; i++) {
      float coefficient = (matrix[i][c] / matrix[c][c]) * -1;
      for (int j = c; j < n; j++) 
        matrix[i][j] += matrix[c][j] * coefficient;
    }
    cout << "Занулен столбец " << c + 1 << "\n";
    printMatrix(matrix) ;
  }

  for (int c = n - 2 ; c > -1; c--) {
    for (int i = n - 2 ; i > c; i--)
      matrix[c][n - 1] -=  matrix[c][i];
      matrix[c][n - 1]	/= matrix[c][c];
      for (int i = 0 ; i < c; i++)
        matrix[i][c] *= matrix[c][n - 1];
  }
  cout << endl;
}
