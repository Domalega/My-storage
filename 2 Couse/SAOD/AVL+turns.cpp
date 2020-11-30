#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

bool rost = 1;

struct Vertex {
	int data;
	int balance;
	struct Vertex* left;
	struct Vertex* right;
};

void FillInc(int* Array, int COUNT) {
	for (int i = 0; i < COUNT; i++) {
		Array[i] = i;
	}
	for (int i = 0; i < COUNT; i++)
		cout << Array[i] << " ";
	cout << endl;
}

void FillDec(int* Array, int COUNT) {
	for (int i = 0; i < COUNT; i++) {
		Array[i] = COUNT - i - 1;
	}
	for (int i = 0; i < COUNT; i++)
		cout << Array[i] << " ";
	cout << endl;
}

void FillRand(int* Array, int COUNT) {
	for (int i = 0; i < COUNT; i++) {
		int random = rand() % 100 + 1;
		Array[i] = random;
	}
	for (int i = 0; i < COUNT; i++)
		cout << Array[i] << " ";
	cout << endl;
}

void Output(Vertex* root) {
	if (root == NULL)
		return;
	Output(root->left);
	if (root->data)
		cout << root->data << " ";
	Output(root->right);
}

void BypassTree(Vertex* root) {
	if (root != NULL) {
		BypassTree(root->left);
		//cout << root->data << " -- balance = " << root->balance << " | ";
		cout << root->data << " ";
		BypassTree(root->right);
	}
}

void LL(Vertex*& p) {
	Vertex* q = p->left;
	p->balance = 0;
	q->balance = 0;
	p->left = q->right;
	q->right = p;
	p = q;
}

void RR(Vertex*& p) {
	Vertex* q = p->right;
	p->balance = 0;
	q->balance = 0;
	p->right = q->left;
	q->left = p;
	p = q;
}

void LR(Vertex*& p) {
	Vertex* q = p->left;
	Vertex* r = q->right;
	if (r->balance < 0)
		p->balance = 1;
	else
		p->balance = 0;
	if
		(r->balance > 0) q->balance = -1;
	else
		q->balance = 0;
	r->balance = 0;
	q->right = r->left;
	p->left = r->right;
	r->left = q;
	r->right = p;
	p = r;
}

void RL(Vertex*& p) {
	Vertex* q = p->right;
	Vertex* r = q->left;
	if (r->balance < 0)
		p->balance = 1;
	else
		p->balance = 0;
	if (r->balance > 0)
		q->balance = -1;
	else
		q->balance = 0;
	r->balance = 0;
	q->left = r->right;
	p->right = r->left;
	r->right = q;
	r->left = p;
	p = r;
}

void Add_AVL_Tree(int X, Vertex*& p) {
	int height = 0;
	if (p == NULL) {
		p = new Vertex;
		p->data = X;
		p->left = NULL;
		p->right = NULL;
		p->balance = 0;
		rost = 1;
		height++;
	}
	else if (p->data > X) {
		Add_AVL_Tree(X, *&p->left);
		if (rost == 1) {
			if (p->balance > 0) {
				p->balance = 0;
				rost = 0;
			}
			else if (p->balance == 0) {
				p->balance = -1;
			}
			else {
				if (p->left->balance < 0) {
					cout << "LL" << endl;
					LL(p);
					rost = 0;
				}
				else {
					cout << "LR" << endl;
					LR(p);
					rost = 0;
				}
			}
		}
	}
	else if (p->data < X) {
		Add_AVL_Tree(X, *&p->right);
		if (rost == 1) {
			if (p->balance < 0) {
				p->balance = 0;
				rost = 0;
			}
			else if (p->balance == 0) {
				p->balance = 1;
			}
			else {
				if (p->right->balance > 0) {
					cout << "RR" << endl;
					RR(p);
					rost = 0;
				}
				else {
					cout << "RL" << endl;
					RL(p);
					rost = 0;
				}
			}
		}
	}
}

int SumOfElements(Vertex* p) {
	int tempSum = 0;
	if (p == NULL) 
		tempSum = 0;
	else 
		tempSum = p->data + SumOfElements(p->left) + SumOfElements(p->right);
	return tempSum;
}

double AvarangeHeight(Vertex* p, int L) {
	double tempAvarange = 0;
	if (p == NULL)
		tempAvarange = 0;
	else
		tempAvarange = L + AvarangeHeight(p->left, L + 1) + AvarangeHeight(p->right, L + 1);
	return tempAvarange;
}

Vertex* max(Vertex* l, Vertex* r) {
	if (AvarangeHeight(l, 1) >= AvarangeHeight(r, 1))	
		return l;
	else 
		return r;
}

int HeightOfTree(Vertex* p) {
	int tempHeight = 0;
	if (p == NULL)	
		return tempHeight;
	else
		return tempHeight = 1 + HeightOfTree(max(p->left, p->right));
}

int Size(Vertex* p) {
	int tempSize = 0;
	if(p == NULL) 
		tempSize = 0;
	else 
		tempSize = 1 + Size(p->left) + Size(p->right);
	return tempSize;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Vertex* root = NULL;
	const int COUNT = 100;
	int Array[COUNT] = { 0 };
	FillRand(Array, COUNT);
	cout << endl << endl;
	for (int i = 0; i < COUNT; i++) {
		Add_AVL_Tree(Array[i], *&root);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
	cout << "Сумма элементов: "<< SumOfElements(root) << endl;
	cout << "Количество элементов: " << COUNT << endl;
	cout << "Высота дерева: " << HeightOfTree(root) << endl;
	cout << "Средняя высота дерева: " << AvarangeHeight(root, 1)/ Size(root) << endl;
	Output(root);
	cout << endl << endl;

	/*FillInc(Array, COUNT);
		cout << endl << endl;
	for (int i = 0; i < COUNT; i++) {
		Add_AVL_Tree(Array[i], *&root);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
	cout << "Сумма элементов: "<< SumOfElements(root) << endl;
	cout << "Количество элементов: " << COUNT << endl;
	cout << "Высота дерева: " << HeightOfTree(root) << endl;
	cout << "Средняя высота дерева: " << AvarangeHeight(root, 1)/ Size(root) << endl;
	Output(root);
	cout << endl << endl;

	FillDec(Array, COUNT);
	cout << endl << endl;
	for (int i = 0; i < COUNT; i++) {
		Add_AVL_Tree(Array[i], *&root);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
	cout << "Сумма элементов: "<< SumOfElements(root) << endl;
	cout << "Количество элементов: " << COUNT << endl;
	cout << "Высота дерева: " << HeightOfTree(root) << endl;
	cout << "Средняя высота дерева: " << AvarangeHeight(root, 1)/ Size(root) << endl;
	Output(root);
	cout << endl << endl;*/
}