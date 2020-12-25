#include <cstring>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <cmath>

int const N = 4000;
int VR = 0;
int HR = 0;

using namespace std;

// variant 105 	2	2	1	2	1

struct record1 {
	char FIO[30];
	short int DepartmentNumber; 
	char Post[22]; 
	char data[10]; 
};

struct Queue {
	record1 record1_Q;
	struct Queue* next;
};

typedef struct Vertex{
	record1 Data;
	int bal;
	struct Vertex *Left;
	struct Vertex *Right;
	struct Vertex *next;
} Vertex;

struct Coding {
    char symbol; // Код символа
    int frequency; // Количество поялвений
    float probability; // Вероятность появления
    short int length; // Длинна код. слова
    char* codeword; // Кодовое слово
};

void ReadBase(record1 *&DataBase) {
	int i;
	FILE *fp;
	fp = fopen("testBase2.dat", "rb");
	DataBase = new struct record1[N];
	i = fread((record1*)DataBase, sizeof(record1), N, fp);
	fclose(fp);
}

bool Less(record1 DataBase1, record1 DataBase2) {
	char temp1[3] = {0};
	char temp2[3] = {0};	
	temp1[0] = DataBase1.data[0];
	temp1[1] = DataBase1.data[1];	
	temp2[0] = DataBase2.data[0];
	temp2[1] = DataBase2.data[1];	
	if (strcmp(temp1, temp2) > 0) return 1;
	else if (strcmp(temp1, temp2) == 0) 
		if (strcmp(DataBase1.FIO, DataBase2.FIO) > 0) return 1;
	return 0;
}

void Heap(record1 *DataBase, int left, int right) {
	struct record1 x;
	x = DataBase[left];
	int i = left;
	while (1) {
		int j = 2 * i;
		if (j > right) break;
		if (j < right && Less(DataBase[j + 1], DataBase[j])) j++;
		if (Less(x, DataBase[j])) break;
		DataBase[i] = DataBase[j];
		i = j;
	}
	DataBase[i] = x;
}

void HeapSort(record1 *DataBase ) {
	int left = (N / 2) + 1;
	while (left > 0) {
		Heap(DataBase, left, N);
		left--;
	}
	int right = N;
	while (right > 1) {
		swap(DataBase[1], DataBase[right]);
		right--;
		Heap(DataBase, 1, right);
	}
}

void Create_Index_Massive(record1 *DataBase, record1 *arrayOfPtr) {
	int i = 1;
	while (i != 4001) {
		DataBase[i] = *arrayOfPtr;
		arrayOfPtr++;
		i++;
	}
}

void Read_20_lines(record1 *DataBase, record1 *arrayOfPtr) {
	int count = 0, k;
	for (int i = 1; i < N + 1;) {
		while (count < 20) {
			cout << i << ")\t" << DataBase[i].FIO;
			cout << "\t" << DataBase[i].DepartmentNumber;
			cout << "\t" << DataBase[i].Post;
			cout << "\t" << DataBase[i].data << "\n";
			count++;
			i++;
		}
		cout << "\n 20 more pages?(1 - yes | 0 - no)  1 or 0  \n";
		cin >> k;
		if (k == 1) 
			count = 0;
		else 
			break;
	}
}

void Read_all_lines(record1 *DataBase, record1 *arrayOfPtr) {
	for (int i = 1; i < N + 1; i++) {
			cout << i << ")\t" << DataBase[i].FIO;
			cout << "\t" << DataBase[i].DepartmentNumber;
			cout << "\t" << DataBase[i].Post;
			cout << "\t" << DataBase[i].data << "\n";
	}
	system("pause");			
}

void Bsearch(record1* DataBase, Queue* head, bool flag) {
	Queue* ptr= head;
	Queue* last = new Queue;
	char key[3] = {0}, k[3] = {0};
	int mid, left = 0, right = 4000, compare;
	cout << "Input key: ";
	cin >> key[0] >> key[1];
	while (left < right) {
		mid = (left + right) / 2;
		k[0] = DataBase[mid].data[0];
		k[1] = DataBase[mid].data[1];
		compare = strcmp(k, key);
		if (compare < 0) {
			left = mid + 1;
		}
		else if(compare == 0 || compare > 0) {
			right = mid;
		}
	}
	if (compare == -1) {
		mid++;
		k[0] = DataBase[mid].data[0];
		k[1] = DataBase[mid].data[1];
	}
	if (strcmp(k, key) == 0) {
		while (1) {
			if (strcmp(k, key) != 0) {
				ptr->next = NULL;
				break;
			}
			ptr->record1_Q = DataBase[mid];
			last = ptr;
			ptr = new Queue;
			last->next = ptr;
			mid++;
			k[0] = DataBase[mid].data[0];
			k[1] = DataBase[mid].data[1];
		}
	}
	else 
		head = NULL;	
	if(head != NULL && flag == 1){
		int i = 1;
		for (ptr= head; ptr->next != NULL; ptr = ptr->next) {
			cout << i << ")\t" << ptr->record1_Q.FIO;
			cout << "\t" << ptr->record1_Q.DepartmentNumber;
			cout << "\t" << ptr->record1_Q.Post;
			cout << "\t" << ptr->record1_Q.data << "\n";
			i++;
		}
		system("pause");
	}
	if(flag == 0) {}
	else {
		cout << "not found" << endl;
		system("pause");
	}
}

void B2Insert(Vertex **p, record1 DataBase){
	Vertex *q;
	if((*p) == NULL) {
		(*p) = new Vertex;
		(*p)->Data = DataBase;
		(*p)->Left = (*p)->Right = (*p)->next = NULL;
		(*p)->bal = 0;
		VR = 1;
	} 
	else {
		if((*p)->Data.DepartmentNumber > DataBase.DepartmentNumber){
			B2Insert(&((*p)->Left), DataBase);
			if(VR == 1){
				if((*p)->bal == 0){
					q = (*p)->Left;
					(*p)->Left = q->Right;
					q->Right = (*p);
					(*p) = q;
					q->bal = 1;
					VR = 0;
					HR = 1;
				} 
				else {
					(*p)->bal = 0;
					HR = 1;
				}
			} 
			else 
				HR = 0;
		} 
		else if((*p)->Data.DepartmentNumber < DataBase.DepartmentNumber){
			B2Insert(&((*p)->Right), DataBase);
			if(VR == 1){
				(*p)->bal = 1;
				HR = 1;
				VR = 0;
			} else if(HR == 1){
				if((*p)->bal > 0){
					q = (*p)->Right;
					(*p)->Right = q->Left;
					q->bal = 0;
					(*p)->bal = 0;
					q->Left = (*p);
					(*p) = q;
					VR = 1;
					HR = 0;
				} else HR = 0;
			}
		}else if((*p)->Data.DepartmentNumber == DataBase.DepartmentNumber){
				Vertex *q = (*p);
				for(;q->next != NULL; q = q->next){};
				q->next = new Vertex;
				q->next->Data = DataBase;
				q->next->Left = q->next->Right = q->next->next = NULL;
		}
	} 
}

void BypassTree(Vertex *p){
	Vertex *q;
	if(p != NULL){
		BypassTree(p->Left);
		cout << "\t" << p->Data.FIO;
		cout << "\t" << p->Data.DepartmentNumber;
		cout << "\t" << p->Data.Post;
		cout << "\t" << p->Data.data << "\n";
		BypassTree(p->Right);
	}
}

void QuickSort(Coding* A, int R, int L) {
    while (L < R) {
        float x = A[L].probability;
        int i = L;
        int j = R;
        while (i <= j) {
            while (A[i].probability > x)
                i++;
            while (A[j].probability < x)
                j--;
            if (i <= j) {
                char tmp_ch;
                tmp_ch = A[i].symbol;
                A[i].symbol = A[j].symbol;
                A[j].symbol = tmp_ch;

                int tmp_q;
                tmp_q = A[i].frequency;
                A[i].frequency = A[j].frequency;
                A[j].frequency = tmp_q;

                float tmp_prop;
                tmp_prop = A[i].probability;
                A[i].probability = A[j].probability;
                A[j].probability = tmp_prop;
                i++;
                j--;
            }
        }

        if (j - L > R - i) {
            QuickSort(A, R, i);
            R = j;
        }
        else {
            QuickSort(A, j, L);
            L = i;
        }
    }
}

int Up(int n, float q, Coding *&code){
	int j = n - 2;
	for(int i = n - 2; i >= 1; i--) {
		if(code[i-1].probability<q) {
			code[i].probability = code[i-1].probability;
		} 
		else {
			j = i;
			code[j].probability = q;
			return j;
		}
	}
	j = 0;
	code[j].probability = q;
	return j;
}

void Down(int n, int j, Coding *&code){
	char* S = new char[n + 2];
	int l = code[j].length;
	for(int i = 0; i <= n - 1; i++) 
		S[i] = code[j].codeword[i];
	for(int i = j; i <= n - 2; i++) {
		for(int t = 0; t <= n - 1; t++) 
			code[i].codeword[t] = code[i+1].codeword[t];
		code[i].length = code[i + 1].length;
	}
	
	for(int i = 0; i < n; i++) 
		code[n - 2].codeword[i] = S[i];
	for(int i = 0; i < n; i++) 
		code[n - 1].codeword[i] = S[i];
		
	code[n - 2].codeword[l - 1] = '0';
	code[n - 1].codeword[l - 1] = '1';
	code[n - 2].codeword[l] = '\0';
    code[n - 1].codeword[l] = '\0';
	code[n - 2].length = l + 1;
	code[n - 1].length = l + 1;
}

void Huffman(Coding*& code, int n, float *P, int nV){
	if(n == 1){
            code[0].codeword[0] = '0';
            code[1].codeword[0] = '1';
			code[0].codeword[1] = '\0';
            code[1].codeword[1] = '\0';
            code[0].length = code[0].length + 1;
            code[1].length = code[1].length + 1;
	}
	else{
		float q = code[n - 1].probability + code[n - 2].probability;
		int j = Up(n, q, code);
		Huffman(code, n - 1,P, nV);
		Down(n, j, code);
		if(n == nV){
			for(int i = 0; i < n; i++){
				code[i].probability = P[i];
				code[i].length--;
			}
		}
	}
}

void tabSym(Coding*& code, int& numSymbols) {
    int nSym[256] = {0};
    int totalNums = 0;
    char ch;
    fstream file("testBase2.dat", ios::in | ios::binary);
    while (!file.read((char*)&ch, sizeof(ch)).eof()) {
        totalNums++;
        if (int(ch) < 0)
            nSym[int(ch) + 256]++;
        else
            nSym[int(ch)]++;
    }
    file.close();
    for (int i = 0; i < 256; i++)
        if (nSym[i] != 0)
            numSymbols++;
    code = new Coding[numSymbols];
    int temp = 0;
    float *P = new float[256];
    for (int i = 0; i < 256; i++) {
        if (nSym[i] != 0) {
            code[temp].symbol = char(i);
            code[temp].frequency = nSym[i];
            code[temp].probability = (float)nSym[i] / (float)totalNums;
            temp++;
        }
    }
    QuickSort(code, numSymbols - 1, 0);
    for (int i = 0; i <= numSymbols - 1; i++) {
    	P[i] = (float)code[i].frequency / (float)totalNums;
    	code[i].codeword = new char[256];
    	code[i].length = 0;
	}
    Huffman(code, numSymbols, P, numSymbols);
}

void printTab(Coding* code, int numSymbols) {
    system("CLS");
    cout  << "Code symbol          Frequency               Probability                    Length                           Code          "  << "\n";
    float H = 0, L_avarange = 0;
    for (int i = 0; i < numSymbols; i++) {
        H += code[i].probability * log2(code[i].probability);
        L_avarange += (float)code[i].length * code[i].probability;
        cout << i << " \\"<< setw(7) << (int)(unsigned char)code[i].symbol << setw(4) << "|"
            << setw(15) << code[i].frequency << "   |"
            << setw(23) << fixed << code[i].probability<< "   |"
            << setw(23) << code[i].length << "   |"
            << setw(29) << code[i].codeword << "   \n";
    }
    cout << "\n\n" << "H(entropy): " << -H << "\n";
    cout << "Length (average) : " << L_avarange << "\n";
}

int main() {
	bool flag;
	int userInput = 0, count = 0, numSymbols = 0;
	char key;
    struct Coding *codeH = NULL;
	struct Vertex *Root = NULL;
	struct Queue *p;
	struct Queue *head = new Queue;
	struct record1 *arrayOfPtr = new record1;
	struct record1 *DataBase = new record1[N];
	while (userInput < 9) {
		system("CLS");
		cout << "1) Print 20 first lines\n";
		cout << "2) Print all lines\n";
		cout << "3) Sort Base and print 20 first lines(HeapSort)\n";
		cout << "4) Sort Base and print all lines(HeapSort)\n";
		cout << "5) Bsearch\n";		
		cout << "6) B Tree\n";
		cout << "7) Huffman`s Coding\n";
		cout << "8) Exit\n";
		cin >> userInput;
		system("CLS");
		switch (userInput) {
		case 1:
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			Read_20_lines(DataBase, arrayOfPtr);
			break;

		case 2:
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			Read_all_lines(DataBase, arrayOfPtr);
			break;
		
		case 3:
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			HeapSort(DataBase);
			Read_20_lines(DataBase, arrayOfPtr);
			break;

		case 4:
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			HeapSort(DataBase);
			Read_all_lines(DataBase, arrayOfPtr);
			break; 

		case 5:
			flag = 1;
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			HeapSort(DataBase);
			Bsearch(DataBase, head, flag);
			break;			

		case 6:
			flag = 0;
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);
			HeapSort(DataBase);
			Bsearch(DataBase, head, flag);
			for(p = head; p->next != NULL; p = p->next)
				B2Insert(&Root, p->record1_Q);
			BypassTree(Root);
			system("pause");
			break;

		case 7: {
			ReadBase(arrayOfPtr);
			Create_Index_Massive(DataBase, arrayOfPtr);	
    		tabSym(codeH, numSymbols);
    		printTab(codeH, numSymbols);
			system("pause");	
			break; }
				
		case 8:
			exit(0);
			break;
			
		}
	}
	delete(arrayOfPtr);
	delete(DataBase);
	return 0;
}
