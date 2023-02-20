#include <bits/stdc++.h>
#define long long ll
using namespace std;
vector<vector<int>> ok;
void rec(vector<int> v, int idx, int trg, vector<int> ans)
{
    if (idx == v.size())
    {
        if (trg == 0)
        {
            ok.push_back(ans);
            return;
        }
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx and v[i] == v[i - 1])
        {
            continue;
        }
        if (v[i] > trg)
        {
            break;
        }
        ans.push_back(v[i]);
        rec(v, i + 1, trg - v[i], ans);
        ans.pop_back();
    }
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 4, 5};
    sort(v.begin(), v.end());
    rec(v, 0, 4, {});
    for (auto i : ok)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}