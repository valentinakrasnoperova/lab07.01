#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int** a, int rowCount, int colCount, int Low, int High);
void print(int** a, int rowCount, int colCount);
void sort(int** a, int rowCount, int colCount);
void change(int** a, int col1, int col2, int rowCount);
void sum(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -12;
    int High = 37;

    int rowCount = 7;
    int colCount = 9;

    int **a=new int*[rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    create(a, rowCount, colCount, Low, High);
    print(a, rowCount, colCount);
    sort(a, rowCount, colCount);
    print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    sum(a, rowCount, colCount, S, k);
    print(a, rowCount, colCount);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;

}
void create(int** a, int rowCount, int colCount, int Low, int High) {
    for (int i=0;i<rowCount;i++)
        for (int j = 0; j < colCount; j++)
        {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
}
void print(int** a, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void sort(int** a, int rowCount, int colCount) {
    for (int i = 0; i <colCount-1; i++)
        for (int j = 0; j < colCount - i - 1; j++)
            if ((a[0][j] > a[0][j + 1])
                || (a[0][j] == a[0][j + 1] && a[1][j] > a[1][j + 1])
                || (a[0][j] == a[0][j + 1] && a[1][j] == a[1][j + 1] && a[2][j] > a[2][j + 1]))
                change(a, j, j+1, rowCount);
}
void change(int** a,int col1, int col2, int rowCount) {
    int tmp;
    for (int row = 0; row < rowCount; row++)
    {
        tmp = a[row][col1];
        a[row][col1] = a[row][col2];
        a[row][col2] = tmp;
    }
}
void sum(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] > 0 || (a[i][j] % 3 != 0))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}