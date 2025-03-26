//MERGE SORT
#include <bits/stdc++.h>
using namespace std;
void MERGE(int arr[], int start, int mid, int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MERGESORT(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        MERGESORT(arr, start, mid);
        MERGESORT(arr, mid + 1, end);
        MERGE(arr, start, mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MERGESORT(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
