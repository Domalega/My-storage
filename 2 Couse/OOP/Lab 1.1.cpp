///Выполнили студенты ИП-915 Врабий Артем, Домалега Владимир, Майненгер Герман

#include <iostream>
#include <time.h>

using namespace std;


int main()
{
	/// Для удобности восприятия размер массива установлен на 20х20, для изменения переменные l и w меняются на 200
	int l = 20;
	int w = 20;
	int k = 0;
	int left = 0, right = l, up = 1, down = w - 2;
	srand (time(NULL));
	setlocale(LC_ALL, "Russian");

	//Инициализация двумерного массива

	int** mas = new int* [l];
	for (int i = 0; i < l; i++)
	{
		mas[i] = new int[w];
	}
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			mas[i][j] = rand() % 256;
			cout.width(3);
			cout << mas[i][j] << ' ';
		}
		cout << endl ;
	}
	cout << endl;

	///////////	по правым диагоналям, начиная с правого верхнего элемента

	cout << "По правым диагоналям, начиная с правого верхнего элемента" << endl <<endl;

	k = 0;
	int* odmas = new int[l * w];
	for (int i = l - 1; i > -1; i--)
		for (int j = 0; j < w - i; j++) {
			odmas[k] = mas[j][i + j];
			k++;
		}
	for (int i = 0; i < l - 1; i++)
		for (int j = 1; j < w - i; j++) {
			odmas[k] = mas[i + j][j - 1];
			k++;
		}
	for (int i = 0; i < l * w; i++)
	{
		cout << odmas[i] << ' ';
	}
	cout << endl << endl;

	///////////	по левым диагоналям, начиная с левого верхнего элемента

	cout << "По левым диагоналям, начиная с левого верхнего элемента" << endl << endl;

	k = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < i + 1; j++) {
			odmas[k] = mas[i - j][j];
			k++;
		}
	for (int i = 1; i < l; i++)
		for (int j = l - 1; j > i - 1; j--) {
			odmas[k] = mas[j][i + l - j - 1];
			k++;
		}
	for (int i = 0; i < l * w; i++)
	{
		cout << odmas[i] << ' ';
	}
	cout << endl<<endl;





	//	по спирали, начиная с левого верхнего элемента

	cout << "По спирали, начиная с левого верхнего элемента" << endl << endl;

	k = 0;

	for (int n = 0; n < l / 2; n++) {
		
		for (int i = left; i < right; i++) {
			odmas[k] = mas[up - 1][i];
			k++;
		}
		for (int i = up; i < down + 1; i++) {
			odmas[k] =  mas[i][right - 1];
			k++;
		}
		for (int i = right - 1; i > left - 1; i--) {
			odmas[k] = mas[down + 1][i];
			k++;
		}
		for (int i = down; i > up - 1; i--) {
			odmas[k] = mas[i][left];
			k++;
		}
		left++;
		right--;
		up++;
		down--;
	}
	for (int i = 0; i < l * w; i++)
	{
		cout << odmas[i] << ' ';
	}
	cout << endl << endl;

	//	по спирали, начиная с центрального элемента

	cout << "По спирали, начиная с центрального элемента" << endl <<endl;

	left = l / 2 - 1;
	right = l / 2 + 1;
	up = l / 2;
	down = l / 2 - 1;
	k = 0;
	for (int n = 0; n < l / 2; n++) {
		for (int i = up; i < down + 1; i++) {
			odmas[k] = mas[i][left];
			k++;
		}
		for (int i = left; i < right; i++) {
			odmas[k] = mas[down + 1][i];
			k++;
		}
		for (int i = down; i > up - 1; i--) {
			odmas[k] = mas[i][right - 1];
			k++;
		}
		for (int i = right - 1; i > left - 1; i--) {
			odmas[k] = mas[up - 1][i];
			k++;
		}		
		left--;
		right++;
		up--;
		down++;

	}

	for (int i = 0; i < l * w; i++)
	{
		cout << odmas[i] << ' ';
	}
	cout << endl << endl;

	//Очищение памяти

	delete[] odmas;

	for (int i = 0; i < l; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

