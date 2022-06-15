#include<bits/stdc++.h>
using namespace std;
void zero(vector<int> &v)
{

    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == 0)
        {
            for(int j = i  ; j < v.size() ; j++)
        {
            if(v[j] != 0)
            {
                swap(v.at(j), v.at(i));
            }
        }
        }
    }

}


int main()
{
   vector<int> v;
   int n;
   cin >> n;
   for(int i = 0; i < n; i++)
   {
       int ele; cin >> ele;
       v.push_back(ele);
   }

   zero(v);
// for(int i = 0; i < v.size();)
// {
//     if(v.at(i) == 0)
//     {
//         for(int j = i; j < v.size() - 1; j++)
//         {
//             swap(v.at(j), v.at(j + 1));
//         }
//     }


//     else
//     {
//         i++;
//     }

    
// }

   for(int i = 0; i < v.size(); i++)
   {
       cout << v.at(i) << " ";
   }
}