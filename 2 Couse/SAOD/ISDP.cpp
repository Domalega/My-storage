#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

struct Vertex {
    int data;
    struct Vertex* left;
    struct Vertex* right;
};

void BypassTree(Vertex* p) { // Обход дерева слева направо 
    if (p != NULL) {
        BypassTree(p->left);
        cout << p->data << " ";
        BypassTree(p->right);
    }
}

void AddNumnerRecursively(Vertex*& p, int Number) { // Рекурсивное добавление элементов в дерево
    if (p == NULL) {
        p = new Vertex;
        p->data = Number;
        p->left = NULL;
        p->right = NULL;
    }
    else if (p->data < Number)
        AddNumnerRecursively(p->right, Number);
    else if (p->data > Number)
        AddNumnerRecursively(p->left, Number);
}

void Remove(int Delete, Vertex** Root) {
    Vertex** p = Root; // p - адресс адресса удаляемой вершина
    Vertex* q, * r, * s; // q-адресс удаляемой , r-адресс самой правой веришны левого поддерева , s - указатель на r
    while ((*p) != NULL) {
        if (Delete < (*p)->data) 
            p = &((*p)->left);
        else if (Delete > (*p)->data)
            p = &((*p)->right);
        else break;
    }
    if ((*p) != NULL) {
        q = *p;
        if (q->left == NULL)*p = q->right;
        else if (q->right == NULL)*p = q->left;
        else {
            r = q->left;
            s = q;
            if (r->right == NULL) {
                r->right = q->right;
                *p = r;
            }
            else {
                while (r->right != NULL) {
                    s = r;
                    r = r->right;
                }
                s->right = r->left;
                r->left = q->left;
                r->right = q->right;
                *p = r;
            }
            delete(q);
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Vertex* Root = NULL;
    int MasNumber[10] = { 83,33,38,53,61,76,34,42,74,47 };
    for (int i = 0; i < 10; i++) 
        AddNumnerRecursively(Root, MasNumber[i]);
    cout << "Изначальное дерево - ";
    BypassTree(Root);
    cout << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << MasNumber[i] << " - удален. ";
        Remove(MasNumber[i], &Root);
        BypassTree(Root);
        cout << endl << endl;
    }
}