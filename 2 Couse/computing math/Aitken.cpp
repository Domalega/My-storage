#include <iostream>

using namespace std;


void Aitken (double *masX, double **masP,double x, int n){
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < n - i; ++j)
      masP[i][j] = (masP[i - 1][j] * (x - masX[j + i]) - masP[i - 1][j + 1] * (x - masX[j])) / (masX[j]- masX[j + i]);
}

int main() {
  int n = 4;
  double **masP = new double*[n], *masX = new double[n], x = 2.56;
  //masX[n] = {1, 2, 3, 4};
  //masP[0][n] = {1.0000, 1.4142, 1.7321, 2.0000}
  for (int i = 0; i < n ; ++i)
    masP[i] = new double[n - i];

  cout << "\nКоординаты точек:\n";
  for (int i = 0;i < n; ++i)  
    cin >> masX[i] >> masP[0][i];

  Aitken(masX, masP, x, n);

  cout << "\n";
  for (int i = 0; i < n; ++i){
    cout << i + 1 << " step | " ;
    for (int j = 0; j < n - i; ++j)
      cout << masP[i][j] << "\t\t";
    cout << "\n";
  }
  return 0;
}