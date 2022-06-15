#include<bits/stdc++.h>
using namespace std;
void rev(vector<int> &v)
{
 for(int i=0 , j = v.size() - 1; i<(v.size())/2 ; i++ ,j--) 
    {
        swap(v[i],v[j]);
    }

}
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
    

    // for(int i=0 , j = v.size() - 1; i<n/2 ; i++ ,j--) 
    // {
    //     swap(v[i],v[j]);
    // }

    rev(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
}


}