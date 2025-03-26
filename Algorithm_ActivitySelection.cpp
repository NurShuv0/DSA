#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#define nl "\n"
#define sp " "
#define ll long long
using namespace std;
struct activity
{
    int start, finish;
};
bool activityCompare(activity s1, activity s2)
{
    return s1.finish < s2.finish;
}
void printMaxActivity(activity arr[], int n)
{
    sort(arr, arr + n, activityCompare);
    cout << "Following activities are selected: ";
    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")";
    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << "," << arr[j].finish << ")";
            i = j;
        }
    }
}
int main()
{
    activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivity(arr, n);
}