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
        }
        return;
    }

    ans.push_back(v[idx]);
    rec(v, idx + 1, trg - v[idx], ans);
    ans.pop_back();
    while (idx < v.size() - 1 and v[idx] == v[idx + 1])
        idx++;
    rec(v, idx + 1, trg, ans);
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 4, 5};
    sort(v.begin(), v.end());
    // vector<int> ans;
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