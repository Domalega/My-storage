#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

struct Vertex {
	int data;
	struct Vertex* left;
	struct Vertex* right;
};

void BypassTree(Vertex* p) {
	if (p != NULL) {
		BypassTree(p->left);
		cout << p->data << " ";
		BypassTree(p->right);
	}
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

float SizeTree(Vertex* p) {
	int size;
	if (p == NULL) size = 0;
	else
		size = 1 + SizeTree(p->left) + SizeTree(p->right);
	return size;
}

int CheckSum(Vertex* p) {
	int s;
	if (p == NULL) s = 0;
	else
		s = p->data + CheckSum(p->left) + CheckSum(p->right);
	return s;
}

int High(Vertex* p) {
	int hight;
	if (p == NULL) hight = 0;
	else
		hight = 1 + max(High(p->left), High(p->right));
	return hight;
}

float SDP(Vertex* p, int L) {
	float sum;
	if (p == NULL) sum = 0;
	else
		sum = L + SDP(p->left, L + 1) + SDP(p->right, L + 1);
	return sum;
}

void AddRecurs(Vertex*& p, int d) {
	if (p == NULL) {
		p = new Vertex;
		p->data = d;
		p->left = NULL;
		p->right = NULL;
	}
	else if (p->data < d)
		AddRecurs(p->right, d);
	else if (p->data > d)
		AddRecurs(p->left, d);
}

int Search(Vertex* p, int X) {
	while (p != NULL) {
		if (p->data < X)p = p->right;
		else if (p->data > X)p = p->left; 
			else break;
	}
	if (p != NULL) {
		X = p->data;
		cout << "Элемент найден" << endl;
	}
	else
		cout << "Элемент не найден" << endl;
	return X;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int L = 0, x;
	Vertex* root = NULL;

	cout << "Рекурсивно: " << endl;
	for (int i = 0; i < 100; i++) 
		AddRecurs(root, rand() % 1000);
	BypassTree(root);

	cout << endl << "Размер дерева: " << SizeTree(root);
	cout << endl << "Контрольная сумма: " << CheckSum(root);
	cout << endl << "Высота: " << High(root);
	cout << endl << "Сумма Длинн Путей: " << SDP(root, 1);
	cout << endl << "Средняя высота: " << SDP(root, 1) / SizeTree(root);
	cout << endl << "Введите элемент, необходимый найти: ";
	cin >> x;
	Search(root, x);
	return 0;
}