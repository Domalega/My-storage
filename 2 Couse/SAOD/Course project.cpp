#include <cstring>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

int const N = 4000;

using namespace std;

// Вариант 106 	2	2	1	2	1



struct record1 {
	char FIO[30];
	short int DepartmentNumber; 
	char Post[22]; 
	char data[10]; 
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
		cout << "\n 20 more pages?(1 - yes | 0 - no)  1 or 0  ";
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

//void BinSearchAll(struct record1* DataBase, int left, char key) {
	//int midd = 0;
	//int right = N;
	//while(true) {
		//midd = (left + right) / 2;
		//if(key <)
	//}	
//}

int main() {
	int userInput = 0;
	char key;
	struct record1 *arrayOfPtr = new record1;
	struct record1 *DataBase = new record1[N];
	while (userInput < 7) {
		system("CLS");
		cout << "1) Print 20 first lines\n";
		cout << "2) Print all lines\n";
		cout << "3) Sort Base and print 20 first lines(HeapSort)\n";
		cout << "4) Sort Base and print all lines(HeapSort)\n";
		cout << "5) Bsearch\n";		
		cout << "6) Exit\n";
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

		//case 5:
		//	ReadBase(arrayOfPtr);
		//	Create_Index_Massive(DataBase, arrayOfPtr);
		//	HeapSort(DataBase);
		//	cout << "Enter the key\n";
		//	cin >> key;
		//	BinSearchAll(DataBase, 0, key);
		//	Read_all_lines(DataBase, arrayOfPtr);
		//	break;
				
		case 6:
			exit(0);
			break;
		}
	}
	delete(arrayOfPtr);
	delete(DataBase);
	return 0;
}
