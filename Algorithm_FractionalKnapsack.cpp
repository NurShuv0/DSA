#include<iostream>
#include<algorithm>
#include<iomanip>
#include<numeric>
#define ll long long 
#define nl "\n"
#define sp " "
using namespace std;
struct item{
    int value, weight;
};
bool cmp(struct item a,struct item b)
{
    double r1 = a.value/a.weight;
    double r2 = b.value/b.weight;
    return r1 > r2;
}
double fractionalKnapsack(struct item arr[], int N, int size)
{
    sort(arr, arr + size, cmp);
    double curWeight = 0.0, rem = 0.0;
    double finalValue = 0.0;
    for(int i = 0; i < size; i++)
    {
        if(curWeight + arr[i].weight <= N)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            rem = N - curWeight;
            finalValue += arr[i].value * (rem/ arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int N = 60;
    item arr[] = {{100, 10}, {280, 40}, {120, 20}, {120, 24}};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout <<fixed << setprecision(3) << "Maximum profit earned is: " << fractionalKnapsack(arr, N, size)<<sp << "Units";
}