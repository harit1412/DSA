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

for(int i = 0; i < n-1; i++)
{
    swap(v.at(i), v.at(i+1));
}

for(int i = 0; i < n; i++)
    cout << v[i] << " ";
}