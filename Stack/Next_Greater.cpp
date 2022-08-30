#include <bits/stdc++.h>
using namespace std;
// #important

// It will Print in reverse we can store it in an vector and print in reverse order {given in gfg}

void PrintGreater(int a[])
{
    stack<int> s;
    s.push(7);
    // cout << "-1 ";
    vector<int> v;
    v.push_back(-1);
    for (int i = 6; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= a[s.top()])
        {
            s.pop();
        }
        if (s.empty())
            cout << "-1 ";
        else
        {
            v.push_back(a[s.top()]);
            // cout << a[s.top()] << " ";
        }
        s.push(i);
    }
    for (auto j : v)
    {
        cout << j << " ";
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    PrintGreater(arr);
    return 0;
}