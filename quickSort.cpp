#include<iostream>
#include<algorithm>
#define nl "\n"
#define sp " "
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
    }



void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr , low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main()
{
    int arr[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    int low = 0;
    int high = 7;
    quickSort(arr , low, high);
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << sp;
    }
    cout << nl;
    return 0;
}