///Выполнили студенты ИП-915 Врабий Артем, Домалега Владимир, Майненгер Герман

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int **arr = new int* [10];

    for (int i = 0; i < 10; i++)
    {
        int j = rand() % 11;
        arr[i] = new int[j];
        arr[i][0] = j;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < arr[i][0]; j++)
        {
            arr[i][j] = rand() % 101;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < arr[i][0]; j++)
        {
            cout << arr[i][j] << ' ';

        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
