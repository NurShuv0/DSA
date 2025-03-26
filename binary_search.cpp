#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, value;
    cout << "ENTER HOW MANY INDEX:";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "ENTER FINDING VALUE:";
    cin >> value;
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (value == arr[mid])
        {
            cout << mid + 1;
            break;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
        }
    }

    return 0;
}
