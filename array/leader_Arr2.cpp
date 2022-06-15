#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int temp = v.at(n - 1);
    cout << temp << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if(v.at(i) > temp)
        {
            cout << v.at(i) << " ";
            temp = v.at(i);
        }
    }
}







