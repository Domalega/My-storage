#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

bool rost = true;
bool decrease = true;

struct Vertex {
	int data;
	int balance;
	struct Vertex* left;
	struct Vertex* right;
};

void FillRand(int* A, int n) {
	bool flag;
	for (int i = 0; i < n;) {
		flag = false;
		int random = rand() % 100;
		for (int j = 0; j < i; j++) {
			if (A[j] == random) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			A[i] = random;
			i++;
		}
	}
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
	if (p == NULL) {
		p = new Vertex;
		p->data = X;
		p->left = NULL;
		p->right = NULL;
		p->balance = 0;
		rost = 1;
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

void LL1(Vertex*& p) {
	Vertex* q = p->left;
	if (q->balance == 0) {
		q->balance = 1;
		p->balance = -1;
		decrease = false;
	}
	else {
		q->balance = 0;
		p->balance = 0;
	}
	p->left = q->right;
	q->right = p;
	p = q;
}

void RR1(Vertex*& p) {
	Vertex* q = p->right;
	if (q->balance == 0) {
		q->balance = -1;
		p->balance = 1;
		decrease = false;
	}
	else {
		q->balance = 0;
		p->balance = 0;
	}
	p->right = q->left;
	q->left = p;
	p = q;
}

void BL(Vertex*& p) { //используется при уменьшении высоты левого поддерева,
	if (p->balance == -1) {
		p->balance = 0;
	}
	else if (p->balance == 0) {
		p->balance = 1;
		decrease = false;
	}
	else if (p->balance == 1) {
		if (p->right->balance >= 0) {
			cout << "RR1" << endl;
			RR1(p);
		}
		else {
			cout << "RL" << endl;
			RL(p);
		}
	}
}

void BR(Vertex*& p) { //используется при уменьшении высоты правого поддерева.
	if (p->balance == 1) {
		p->balance = 0;
	}
	else if (p->balance == 0) {
		p->balance = -1;
		decrease = false;
	}
	else if (p->balance == -1) {
		if (p->left->balance <= 0) {
			cout << "LL1" << endl;
			LL1(p);
		}
		else {
			cout << "LR" << endl;
			LR(p);
		}
	}
}



void delt(Vertex*& ql, Vertex*& q) {
	if (ql->right != nullptr) {
		delt(ql->right, q);
		if (decrease)
			BR(ql);
	}
	else {
		q->data = ql->data;
		q = ql;
		ql = ql->left;
		decrease = true;
	}
}

void DeleteAVL(Vertex*& p, int key) {
	if (p == nullptr);
	else if (p->data > key) {
		DeleteAVL(p->left, key);
		if (decrease)
			BL(p);
	}
	else if (p->data < key) {
		DeleteAVL(p->right, key);
		if (decrease)
			BR(p);
	}
	else {
		Vertex* q = p;
		if (q->right == nullptr) {
			p = q->left;
			decrease = true;
		}
		else if (q->left == nullptr) {
			p = q->right;
			decrease = true;
		}
		else {
			delt(q->left, q);
			if (decrease) 
				BL(p);
		}
		delete q;
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Vertex* root = NULL;
	const int COUNT = 10;
	int Array[COUNT] = { 0 };
	cout << "Заполнение дерева!" << endl << endl;
	FillRand(Array, COUNT);
	Output(root);
	for (int i = 0; i < 10; i++) {
		Add_AVL_Tree(Array[i], *&root);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
	Output(root);

	cout << endl << endl << "Удаление дерева!" << endl << endl;
	for (int i = 0; i < COUNT; i++) {
		DeleteAVL(*&root, Array[i]);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
}