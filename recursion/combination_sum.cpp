#include <bits/stdc++.h>
#define long long ll
using namespace std;

vector<vector<int>> ans;
void rec(vector<int> &arr, int targ, int idx, int curr, vector<int> a)
{
    if (curr > targ)
    {
        return;
    }
    if (idx == arr.size())
    {

        if (curr == targ)
        {

            vector<int> tm;
            if (!a.empty())
                for (auto i : a)
                    tm.push_back(i);
            ans.push_back(tm);
            return;
        }
        return;
    }
    rec(arr, targ, idx + 1, curr, a);
    a.push_back(arr[idx]);
    rec(arr, targ, idx, curr + arr[idx], a);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // vector<vector<int>> ans;
}