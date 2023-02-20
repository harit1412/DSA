#include <bits/stdc++.h>
#define long long ll
using namespace std;
vector<vector<int>> ans = {};
void rec(vector<int> v, int idx, vector<int> ok)
{
    ans.push_back(ok);
    for (int i = idx; i < v.size(); i++)
    {
        if (i != idx)
        {
            if (v[i] == v[i - 1])
            {
                continue;
            }
        }
        ok.push_back(v[i]);
        rec(v, i + 1, ok);
        ok.pop_back();
    }
}

int main()
{
    vector<int> v = {1, 2, 2};
    rec(v, 0, {});
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}