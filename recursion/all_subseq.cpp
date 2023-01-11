#include <bits/stdc++.h>
#define long long ll
using namespace std;

void subseq(int idx, vector<int> v, vector<int> ans)
{
    if (idx == v.size())
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        if(ans.size()==0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    subseq(idx + 1, v, ans);
    ans.push_back(v[idx]);
    subseq(idx + 1, v, ans);
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> ans;
    subseq(0, v, ans);
}