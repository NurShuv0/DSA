#include <iostream>
using namespace std;

void selectionSort(int A[])
{
    int i, j;
    for (i = 0; i < 7; i++)
    {
        int minj = i;
        int minx = A[i];
        for (j = i + 1; j < 8; j++)
        {
            if (A[j] < minx)
            {
                minj = j;
                minx = A[j];
            }
        }
        swap(A[minj], A[i]);
    }
}
int main()
{
    int i;
    int A[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    selectionSort(A);
    for (i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
}