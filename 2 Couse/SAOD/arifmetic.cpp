#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>


using namespace std;

struct coding {
	char symbol;
	unsigned int quantity = 0;
	float ver = 0;
	unsigned short int lengthCW = 0;
	char* codeword;
	double Q;
};

void tableSymbols(coding*& code, int& numsUnique) {
	int Symbols[256] = { 0 };
	int totalNums = 0;
	char ch;

	fstream file("Input.txt", ios::in | ios::binary);

	while (!file.read((char*)&ch, sizeof(ch)).eof()) {
		totalNums++;
		if (int(ch) < 0)
			Symbols[int(ch) + 256]++;
		else
			Symbols[int(ch)]++;
	}
	file.close();

	for (int i = 0; i < 256; i++)
		if (Symbols[i] != 0)
			numsUnique++;

	code = new coding[numsUnique + 1];

	fstream file1("Input.txt", std::ios::in | std::ios::binary);
	int k = 0;
	while (!file1.read((char*)&ch, sizeof(ch)).eof()) {
		for (int i = 0; i < numsUnique; i++) {
			if (code[i].symbol == ch) {
				code[i].quantity++;
				continue;
			}
		}
		code[k].symbol = ch;
		code[k].quantity = 1;
		k++;
	}
	for (int i = 0; i < numsUnique; i++) {
		code[i].ver = code[i].quantity / (float)totalNums;
		cout << code[i].symbol << " = " << code[i].ver << " " << endl;
	}
	file1.close();
}

void dv(int n, double x, int numSymbols) {
	ofstream out;
	out.open("Output.txt");
	for (int i = 0; i < n; i++) {
		x *= 2;
		if (out.is_open())
			out << trunc(x);
		if (x >= 1)
			x--;
	}
	cout << endl << "Compression =  " << ((double)n / (double)numSymbols) * 100 << "%" << endl;
}

void abc_code(coding* code, int numSymbols) {
	int i = 0, m;
	char ch;
	double* l = new double[numSymbols + 1];
	double* h = new double[numSymbols + 1];
	double* r = new double[numSymbols + 1];
	for (int i = 0; i <= numSymbols; i++) {
		r[i] = 0;
		h[i] = 0;
		l[i] = 0;
	}
	r[0] = 1;
	h[0] = 1;
	l[0] = 0;
	code[0].Q = 0;
	cout << endl;
	for (int j = 1; j <= numSymbols; j++) {
		code[j].Q = NULL;
		for (int x = 0; x < j; x++)
			code[j].Q += code[x].ver;
		cout << j << ") " << code[j].Q << endl;
	}
	cout << endl;
	fstream file("Input.txt", ios::in | ios::binary);
	i = 0;
	code[numSymbols].Q = 1;

	while (!file.read((char*)&ch, sizeof(ch)).eof()) {
		i++;
		for (int j = 1; j <= numSymbols; j++) {
			if (ch == code[j - 1].symbol) {
				m = j;
				break;
			}
		}
		l[i] = l[i - 1] + r[i - 1] * code[m - 1].Q;
		cout << "l = " << l[i] << " ";
		h[i] = l[i - 1] + r[i - 1] * code[m].Q;
		cout << "h = " << h[i] << " ";
		r[i] = h[i] - l[i];
		cout << "r = " << r[i] << endl;
	}
	int numK = ceil(-log2(r[i]));
	dv(numK, l[i], numSymbols);
	file.close();
}

int main() {
	int  numSymbols = 0;
	coding* Code = NULL;
	tableSymbols(Code, numSymbols);
	abc_code(Code, numSymbols);
	system("pause");
}
