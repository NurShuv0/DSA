#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &v)
{
    int count = 0;
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                swap(v[j], v[j + 1]);
                for (auto c : v)
                {
                    cout << c << " ";
                }
                cout << "\n";
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> v;
    int nr, sw;

    cin >> nr;

    for (int i = 0; i < nr; i++)
    {
        cin >> sw;
        v.push_back(sw);
    }

    int swapCount = bubbleSort(v);

    for (auto i : v)
        cout << i << " ";
    cout << nl;

    cout << "Total swaps: " << swapCount << nl;

    return 0;
}
