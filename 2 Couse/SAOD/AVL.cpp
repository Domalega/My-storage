#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

struct Vertex {
	int data;
	int balance;
	struct Vertex* left;
	struct Vertex* right;
};

void BypassTree(Vertex* p) {
	if (p != NULL) {
		BypassTree(p->left);
		cout << p->data << ", Balance = " << p->balance << " ";
		BypassTree(p->right);
	}
}

void Add_AVL_Tree(int Data, Vertex** p) {
	bool rost = 1;
	if ((*p) == NULL) {
		(*p) = new Vertex;
		(*p)->data = Data;
		(*p)->left = (*p)->right = NULL;
		(*p)->balance = 0;
		rost = 1;
	}
	else if ((*p)->data > Data) {
		Add_AVL_Tree(Data, &((*p)->left));
		if (rost == 1) {
			if ((*p)->balance > 0) {
				(*p)->balance = 0;
				rost = 0;
			}
			else if ((*p)->balance == 0) {
				(*p)->balance = -1;
				rost = 1;
			}
			else {
				if ((*p)->left->balance < 0) 
					rost = 0;
				else 
					rost = 0;
			}
		}
	}
	else if ((*p)->data < Data) {
		Add_AVL_Tree(Data, &((*p)->right));
		if (rost == 1) {
			if ((*p)->balance < 0) {
				(*p)->balance = 0;
				rost = 0;
			}
			else if ((*p)->balance == 0) {
				(*p)->balance = 1;
				rost = 0;
			}
			else {
				if ((*p)->right->balance > 0)
					rost = 0;
				else
					rost = 0;
			}
		}
	}
	else cout << "Вершина есть в дереве ";
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Vertex* root = NULL;
	const int COUNT = 5;
	int Array[COUNT];
	for (int i = 0; i < COUNT; i++)
		Array[i] = rand() % 100;
	for (int i = 0; i < COUNT; i++)
		cout << Array[i] << " ";
	cout << endl << endl;
	for (int i = 0; i < COUNT; i++) {
		Add_AVL_Tree(Array[i], &root);
		BypassTree(root);
		cout << endl;
	}
	cout << endl;
}