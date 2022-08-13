#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int d;
    cin >> d;
    // first reverse d-1 array...
    for (int i = 0, j = d - 2; i < j; i++,j--)
    {
        swap(v.at(i), v.at(j));
    }
     // then reverse remaining...
    for (int j = d - 1,i = n-1;j < i;j++,i--)
    {
        swap(v.at(i), v.at(j));
    }
    // reverse all;
    for(int i = 0,j = n-1 ; i < j; i++,j--)
    {
       swap(v.at(i), v.at(j));
    }
    for (int i = 0; i < n; i++)
    {
        cout << v.at(i) << " ";
    }
}