

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void Shenon(float* P, float* Q, int* L, int** C, int n) {
	Q[0] = 0;
	L[0] = -log2(P[0]) + 1;
	for (int i = 1; i < n; i++) {
		Q[i] = Q[i - 1] + P[i - 1];
		L[i] = -log2(P[i]) + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < L[i]; j++) {
			Q[i] *= 2;
			C[i][j] = (int)Q[i];
			if (Q[i] >= 1) Q[i] -= 1;

		}
	}
	cout << endl << endl;
}

int Up(int n, float q, float* P) {
	int j = n - 1;
	for (int i = n - 1; i >= 2; i--) {
		if (P[i - 1] < q)
			P[i] = P[i - 1];
		else {
			j = i;
			P[j] = q;
			return j;
		}
	}
	j = 1;
	P[j] = q;
	return j;
}

void Down(int n, int j, int* L, int** C) {
	int S[11];
	for (int i = 1; i <= n; i++) S[i] = C[j][i];
	int l = L[j];
	for (int i = j; i <= n - 2; i++) {
		for (int t = 1; t <= n; t++)
			C[i][t] = C[i + 1][t];
		L[i] = L[i + 1];
	}
	for (int i = 1; i <= n; i++)
		C[n - 1][i] = S[i];
	for (int i = 1; i <= n; i++)
		C[n][i] = S[i];
	C[n - 1][l + 1] = 0;
	C[n][l + 1] = 1;
	L[n - 1] = l + 1;
	L[n] = l + 1;

}

void Huffman(float* P, int* L, int** C, int n) {
	if (n == 2) {
		C[1][1] = 0;
		L[1] = 1;
		C[2][1] = 1;
		L[2] = 1;
	}
	else {
		float q = P[n - 1] + P[n];
		int j = Up(n, q, P);
		Huffman(P, L, C, n - 1);
		Down(n, j, L, C);
	}
}

int Med(int l, int r, float* P) {
	double Sl = 0, Sr = P[r];
	int m;
	for (int i = l; i <= r - 1; i++)
		Sl += P[i];
	m = r;
	while (Sl >= Sr) {
		m -= 1;
		Sl -= P[m];
		Sr += P[m];
	}
	return m;
}

void Fano(int l, int r, int k, int** C, int* L, float* P) {
	int m;
	if (l < r) {
		k += 1;
		m = Med(l, r, P);
		for (int i = l; i <= r; i++) {
			if (i <= m) {
				C[i][k] = 0;
				L[i]++;
			}
			else {
				C[i][k] = 1;
				L[i]++;
			}
		}
		Fano(l, m, k, C, L, P);
		Fano(m + 1, r, k, C, L, P);
	}
}

void Gilbert_Mur(float* P, float* Q, int* L, int** C, int n) {
	float pr = 0;
	for (int i = 1; i <= n; i++) {
		Q[i] = pr + (float)P[i] / 2;
		pr += P[i];
		L[i] = -log2(P[i]) + 2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L[i]; j++) {
			Q[i] *= 2;
			C[i][j] = Q[i];
			if (Q[i] >= 1)
				Q[i] -= 1;
		}
	}
}

int main() {
	srand(time(0));
	int n = 10;
	int L[10];
	int L1[10];
	float Lm = 0, H = 0;
	float P[10] = { 0.21, 0.15, 0.15, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07 },
		P1[11] = { 0,0.21, 0.15, 0.15, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07 },
		P2[11] = { 0,0.21, 0.15, 0.15, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07 },
		P3[11] = { 0,0.07, 0.15, 0.15, 0.07, 0.07, 0.21, 0.07, 0.07, 0.07, 0.07 },
		Q[10],
		Q1[11];

	int** C = new int* [n];
	for (int i = 0; i <= n; i++)
		C[i] = new int[n];

	int** C2 = new int* [n];
	for (int i = 0; i <= n; i++)
		C2[i] = new int[n];

	int** C3 = new int* [n];
	for (int i = 0; i <= n; i++)
		C3[i] = new int[n];

	cout << "Shennon: ";
	Shenon(P, Q, L, C, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < L[i]; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		Lm += P[i] * L[i];
		H -= P[i] * log2(P[i]);
	}
	cout << "Lm = " << Lm << " H = " << H << endl << endl;
	for (int i = 1; i < n + 1; i++) {
		L[i] = 0;
		C[i] = NULL;
		C[i] = new int[n];
	}
	H = Lm = 0;

	cout << "Huffman:" << endl;
	Huffman(P1, L, C, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L[i]; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		Lm += P[i] * L[i + 1];
		H -= P[i] * log2(P[i]);
	}cout << "Lm = " << Lm << " H = " << H << endl << endl;
	for (int i = 1; i < n + 1; i++)
		L[i] = 0;

	cout << endl << "Fano:" << endl;
	int l = 1, r = n;

	Fano(l, r, 0, C2, L, P2);
	H = Lm = 0;
	for (int i = 1; i <= r; i++) {
		
		for (int j = 1; j <= L[i]; j++)
			cout << C2[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		Lm += P[i] * L[i + 1];
		H -= P[i] * log2(P[i]);
	}
	cout << "Lm = " << Lm << " H = " << H << endl << endl;
	for (int i = 0; i < n + 1; i++)
		L[i] = 0;

	cout << endl << "Gilbert_Mur" << endl;
	Gilbert_Mur(P3, Q1, L, C3, n);
	H = Lm = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L[i]; j++)
			cout << C3[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		Lm += P3[i + 1] * L[i + 1];
		H -= P3[i + 1] * log2(P3[i + 1]);
	}
	cout << "Lm = " << Lm << " H = " << H << endl << endl;
	system("pause");
}
