#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

struct Vertex {
    int data;
    int bal;
    struct Vertex* left;
    struct Vertex* right;
};

bool VR = 1, HR = 1;
Vertex* q;

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

int SizeTree(Vertex* p) {
    int size;
    if (p == NULL) size = 0;
    else
        size = 1 + SizeTree(p->left) + SizeTree(p->right);
    return size;
}

int CheckSum(Vertex* p) {
    int sum;
    if (p == NULL) sum = 0;
    else
        sum = p->data + CheckSum(p->left) + CheckSum(p->right);
    return sum;
}

float LengthPath(Vertex* p, int L) {
    int length;
    if (p == NULL) length = 0;
    else
        length = L + LengthPath(p->left, L + 1) + LengthPath(p->right, L + 1);
    return length;
}

float High(Vertex* p) {
    int hight;
    if (p == NULL) hight = 0;
    else
        hight = 1 + max(High(p->left), High(p->right));
    return hight;
}

void AddBTree(Vertex*& p, int d) {
    if (p == NULL) {
        p = new Vertex;
        p->data = d;
        p->left = NULL;
        p->right = NULL;
        p->bal = 0;
        VR = 1;
    }
    else{
        if (p->data > d) {
            AddBTree(p->left, d);
            if (VR == 1) {
                if (p->bal == 0) {
                    q = p->left;
                    p->left = q->right;
                    q->right = p;
                    p = q;
                    q->bal = 1;
                    VR = 0;
                    HR = 1;
                }
                else {
                    p->bal = 0;
                    VR = 1;
                    HR = 0;
                }
            }
            else HR = 0;
        }
        else if (p->data < d) {
            AddBTree(p->right, d);
            if (VR == 1) {
                p->bal = 1;
                HR = 1;
                VR = 0;
            }
            else if (HR == 1) {
                if (p->bal == 1) {
                    q = p->right;
                    p->bal = 0;
                    q->bal = 0;
                    p->right = q->left;
                    q->left = p;
                    p = q;
                    VR = 1;
                    HR = 0;
                }
                else HR = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Vertex* root = NULL;

    for (int i = 0; i < 100; i++)
        AddBTree(root, rand() % 1000);
    BypassTree(root);

    cout << endl << "Размер дерева: " << SizeTree(root);
    cout << endl << "Контрольная сумма: " << CheckSum(root);
    cout << endl << "Высота: " << High(root);
    cout << endl << "Сумма Длинн Путей: " << LengthPath(root, 1);
    cout << endl << "Средняя высота: " << LengthPath(root, 1) / SizeTree(root);
    return 0;
}