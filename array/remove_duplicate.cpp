#include<bits/stdc++.h>
using namespace std;
void dup(vector<int> &v , int n)
{
 for(int i = 1; i < v.size(); i++)
    {
        if(v[i] == v[i - 1])
        {
            for(int j = i; j < v.size() - 1; j++)
            {
                swap(v[j], v[j + 1]);
            }
        }
}
int main()

{
    
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        v.push_back(e);
    }
    
    sort(v.begin(), v.end());
    int n = v.size();


   

    

}