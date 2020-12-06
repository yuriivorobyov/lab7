#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Sort(int** a, const int n);
int first(int** a, int rowCount, int colCount);
int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    int Low = -5;
    int High = 1;
    Create(a, n, Low, High);
    Print(a, n);
    Sort(a, n);
    Print(a, n);
    cout << first(a, n, n);
}
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;


}
void Change(int** a, const int row, const int col, const int colCount)
{
    int tmp;
    tmp = a[row][col];
    a[row][col] = a[row + 1][col + 1];
    a[row + 1][col + 1] = tmp;
}
void Sort(int** a, const int n)
{
    for (int f = 0; f < n - 1; f++)
        for (int f = 0; f < n - 1; f++)
            if (a[f][f] > a[f + 1][f + 1])
                Change(a, f, f, n);
}
int first(int** a, int rowCount, int colCount)
{
    int colNumber = -1;
    int rowNumber = 0;
    for (int i = 0; i < colCount; i++)
    {
        colNumber = -1;
        if (colNumber == -1)
        {
            for (int j = 0; j < rowCount; j++)
            {
                if (a[i][j] >= 0)
                    colNumber = 0;
            }
        }
        if (colNumber != 0)
        {
            rowNumber = i;
            break;
            return rowNumber;
        }
    }
}
