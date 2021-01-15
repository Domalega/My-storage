#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int R = 31;
int ccc = 0;

int count_length(int num) {
	int c = 0;
	for (int i = num; i > 0; i /= 2)
		c++;
	return c;
}

void fix_var(int* codeF, int num, int c, int E) {
	int count = c;
	for (int i = E - 1; i >= 0; i--) {
		codeF[i] = c % 2;
		c /= 2;
	}
	for (int i = E + count - 2; i >= E; i--) {
		codeF[i] = num % 2;
		num /= 2;
	}
}

void elias_y(int* codeY, int num, int c) {
	int E = c - 1;
	for (int i = 0; i < E; i++) 
		codeY[i] = 0;
	for (int i = E + c - 1; i >= E; i--) {
		codeY[i] = num % 2;
		num /= 2;
	}
}

int elias_w(vector<int>& codeW, int num, int c) {
	if (num == 1) {
		codeW.push_back(0);
		return 0;
	}
	while (num != 0) {
		codeW.insert(codeW.begin(), num % 2);
		num /= 2;
	}
	if (c > 2) {
		elias_w(codeW, c - 1, count_length(c - 1));
	}
	return 0;
}


void RLE_fix_var(int* code, int n) {
	int end = 0, num_vec = 0, E = 4, x = 6;
	n--;
	cout << endl << "RLE_fix_var" << endl << endl;
	vector<int> vec;
	vec.push_back(0);
	while (end != n) {
		if (code[end] == 0) 
			vec[num_vec]++;
		if (code[end] == 1) {
			num_vec++;
			vec.push_back(0);
		}
		end++;
	}

	for (int i = 0; i < vec.size(); i++) 
		cout << vec[i] << " ";
	cout << endl;

	for (int i = 0; i < vec.size(); i++) {
		int codeF[R];
		int c = 0;
		for (int j = vec[i]; j > 0; j /= 2) 
			c++;

		fix_var(codeF, vec[i], c, E);
		for (int i = 0; i < E; i++) {
			cout << codeF[i];
			ccc++;
			x--;
		}
		cout << " ";

		for (int i = E; i < E + c - 1; i++) {
			cout << codeF[i];
			ccc++;
			x--;
		}

		for (int k = 0; k < x; k++) 
			cout << " ";
		cout << "   ";
		for (int k = 0; k < x; k++) 
			cout << " ";
	}
	cout << endl;
	cout << "Number of bits before encoding = " << R << endl;
	cout << "Number of bits after encoding = " << ccc << endl;
	double a = (float)ccc / R;
	cout << "Compression = " << a;
}

void RLE_elias_y(int* code, int n) {
	cout << endl;
	cout << endl;
	cout << "RLE_elias_y" << endl;
	ccc = 0;
	int end = 0, num_vec = 0, E = 4, x = 16;
	n--;
	vector<int> vec;
	vec.push_back(0);
	while (end != n) {
		if (code[end] == 0)
			vec[num_vec]++;
		if (code[end] == 1) {
			num_vec++;
			vec.push_back(0);
		}
		end++;
	}
	cout << endl;
	for (int i = 0; i < vec.size(); i++) 
		cout << ++vec[i] << " ";
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		int codeY[R];
		int c = 0;
		for (int j = vec[i]; j > 0; j /= 2) 
			c++;
		elias_y(codeY, vec[i], c);
		E = c - 1;
		for (int i = 0; i < E; i++) {
			cout << codeY[i];
			ccc++;
		}
		cout << " ";
		for (int i = E; i < E + c; i++) {
			cout << codeY[i];
			ccc++;
		}cout << " ";
	}
	cout << endl;
	cout << "Number of bits before encoding = " << R << endl;
	cout << "Number of bits after encoding = " << ccc << endl;
	double a = (float)ccc / R;
	cout << "Compression = " << a;
}

void RLE_elias_w(int* code, int n) {
	ccc = 0;
	cout << endl;
	cout << endl;
	cout << "RLE_elias_w" << endl;
	int end = 0, num_vec = 0;
	n--;
	vector<int> vec;
	vec.push_back(0);
	while (end != n) {
		if (code[end] == 0)
			vec[num_vec]++;
		if (code[end] == 1) {
			num_vec++;
			vec.push_back(0);
		}
		end++;
	}
	cout << endl;
	for (int i = 0; i < vec.size(); i++) 
		cout << ++vec[i] << " ";
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		vector<int> codeW;
		int c = 0;
		for (int j = vec[i]; j > 0; j /= 2)
			c++;
		elias_w(codeW, vec[i], c);
		if (vec[i] > 1)codeW.push_back(0);
		for (int i = 0; i < codeW.size(); i++) {
			if (i == 2 || i == codeW.size() - 1) 
				cout << " ";
			if (i == 5 && codeW.size() > 7) 
				cout << " ";
			cout << codeW[i];
			ccc++;
		}
	}
	cout << endl;
	cout << endl;
	cout << "Number of bits before encoding = " << R << endl;
	cout << "Number of bits after encoding = " << ccc << endl;
	double a = (float)ccc / R;
	cout << "Compression = " << a << endl; // сжатие
}

int main() {
	srand(time(0));
	srand(time(0));
	int n = 30;
	int code[R] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 };
	for (int i = 0; i < R; i++)
		cout << code[i];
	cout << endl;
	RLE_fix_var(code, R);
	RLE_elias_y(code, R);
	RLE_elias_w(code, R);
	system("pause");
}
