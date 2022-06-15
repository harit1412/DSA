#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cin >> n;


for (int i = 0; i < n; i++)
{
    int ele;
    cin >> ele;
    v.push_back(ele);
}
int count = 0;
for (int i = 0; i < n; i++)
{
    if(v.at(i) != 0)
    {
        swap(v.at(i), v.at(count));
        count++;
    }

}
for(int i = 0; i < n; i++)
    cout << v.at(i) << " ";
}