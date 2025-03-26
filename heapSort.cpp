#include <iostream>
#include <algorithm>
#include <iomanip>
#include <array>
#define nl "\n"
#define sp " "
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int l = 2 * i + 1;
    int right = 2 * i + 2;
    int r = 2 * i + 2;
    if (n > l && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
int heapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << arr[i] << sp;
    }*/
}
void printArray(int arr[], int n)
{
    for(int i =0; i < n; i++)
    {
        cout << arr[i] << sp;
    }
}
int main()
{
    int arr[] = {14, 33, 27, 10, 35, 19, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    printArray(arr,n);
}