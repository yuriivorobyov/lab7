#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
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
    Create(a, n, Low, High);
    Print(a, n);
    Calc(a, n, k, High, Low);
    Print(a, n);
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
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
void swipe(int** a, int Max, int Min, int iMax, int iMin, int i)
{
    int tmp = a[i][iMax];
    a[i][iMax] = a[i - 1][iMin];
    a[i - 1][iMin] = tmp;
}

int findMax(int** a, int k, int i, int low)
{
    int Max = low;
    for (int j = 0; j < k; j++) {
        if (Max < a[i][j]) {
            Max = a[i][j];
        }
    }
    return Max;
}

int findMin(int** a, int k, int i, int max)
{
    int Min = max;
    for (int j = 0; j < k; j++) {
        if (Min > a[i][j]) {
            Min = a[i][j];
        }
    }
    return Min;
}

int findIndex(int** a, int i, int num, int k)
{
    int index = 0;
    for (int j = 0; j < k; j++)
    {
        if (a[i][j] == num)
        {
            index = j;
            return index;
            break;
        }
    }
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
            Max = findMax(a, k, i, low);
            iMax = findIndex(a, i, Max, k);
            cout << "Max " << Max << " iMax " << iMax << endl;
        }
        if (i % 2 != 0)
        {
            Min = findMin(a, k, i, max);
            iMin = findIndex(a, i, Min, k);
            cout << "Min " << Min << " iMin " << iMin << endl;
        }

        if (i % 2 == 0)
        {
            swipe(a, Max, Min, iMax, iMin, i);
        }
    }
}