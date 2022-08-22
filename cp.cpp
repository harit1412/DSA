#include <bits/stdc++.h>
using namespace std;
void mat_dekh()
{
     int n;
     cin >> n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
     {
          cin >> v[i];
     }
     int mx = *max_element(v.begin(), v.end());
     sort(v.begin(), v.end());
     vector<int> rem;
     for (int i = 0; i < n; i++)
     {
          rem.push_back(mx - v[i]);
     }
     int idx = rem.size() - 1;
     while (idx >= 0 && rem.at(idx) == 0)
     {
          idx--;
     }
     if (idx == -1)
     {
          cout << "0";
          return;
     }
     int count = 0;
     for (int i = 0; i < n;)
     {
          if (v[i] >= rem[idx])
          {
               v.at(idx) += rem.at(idx);
               rem.at(idx) -= rem.at[idx];
               v.at(i) -= rem[idx];
               rem.at(i) += rem[idx];
               idx--;
               if (v.at(i) == 0)
               {
                    count++;
                    i++;
                    v.erase(v.begin());
                    rem.erase(rem.begin());
               }
          }
          if (v[i] < rem[idx])
          {
               v.at(idx) += v[i];
               rem.at(idx) -= v[i];
               v.erase(v.begin());
               rem.erase(rem.begin());
               i++;
          }
     }
}
int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          mat_dekh();
          cout << "\n";
     }
}