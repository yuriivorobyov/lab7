#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRows(int** a, const int k, const int n, const int Low, const int High);
void CreateRow(int** a, const int i, const int n, const int Low, const int High);
void PrintRows(int** a, const int k, const int n);
void PrintRow(int** a, const int i, const int n);
void Calc(int** a, const int n, int k, int max, int low);
int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    int k;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[k];
    CreateRows(a, k, n, Low, High);
    PrintRows(a, k, n);
    Calc(a, n, k, High, Low);
    PrintRows(a, k, n);
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void CreateRows(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        CreateRow(a, i, n, Low, High);
}
void CreateRow(int** a, const int i, const int n, const int Low, const int High)
{
    for (int j = 0; j < n; j++)
        a[i][j] = Low + rand() % (High - Low + 1);
}
void PrintRows(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
        PrintRow(a, i, n);
    cout << endl;
}
void PrintRow(int** a, const int i, const int n)
{
    for (int j = 0; j < n; j++)
        cout << setw(4) << a[i][j];
    cout << endl;
}
void swipe(int** a, int Max, int Min, int iMax, int iMin, int i)
{
    int tmp = a[i][iMax];
    a[i][iMax] = a[i - 1][iMin];
    a[i - 1][iMin] = tmp;
}

int findMax(int** a, int k, int i, int low, int j, int Max)
{
    {
        if (Max < a[i][j]) {
            Max = a[i][j];
        }
    }
    if (j < k - 1)
    {
        findMax(a, k, i, low, j + 1, Max);
        return Max;
    }
    else
        return 0;


}

int findMin(int** a, int k, int i, int max, int Min, int j)
{
    {if (Min > a[i][j]) {
        Min = a[i][j];
    }
    }
    if (j < k - 1)
    {
        findMin(a, k, i, max, Min, j + 1);
        return Min;
    }
    else
        return 0;

}

int findIndex(int** a, int i, int num, int k, int index, int j)
{
    {
        if (a[i][j] == num)
        {
            index = j;
            return index;
        }
    }
    if (j < k - 1)
    {
        findIndex(a, i, num, k, index, j + 1);
        return index;
    }
    else
        return 0;
}

void Calc(int** a, const int n, int k, int max, int low)
{
    int Max = low;
    int Min = max;
    int iMax = 0;
    int iMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            int index = 0;
            int Max = low;
            Max = findMax(a, k, i, low, 0, Max);
            iMax = findIndex(a, i, Max, k, index, 0);
            cout << "Max " << Max << " iMax " << iMax << endl;
        }
        if (i % 2 != 0)
        {
            int index = 0;
            int Min = max;
            Min = findMin(a, k, i, max, Min, 0);
            iMin = findIndex(a, i, Min, k, index, 0);
            cout << "Min " << Min << " iMin " << iMin << endl;
        }
        if (i % 2 == 0)
        {
            swipe(a, Max, Min, iMax, iMin, i);
        }
    }
}
