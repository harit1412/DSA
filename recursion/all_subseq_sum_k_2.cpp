#include <bits/stdc++.h>
#define long long ll
using namespace std;

// Print any one sequence

bool printsubseq(vector<int> arr, int idx, int k, vector<int> ans, int curr)
{
    if (idx == arr.size())
    {
        if (curr == k)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // Not take
    if (printsubseq(arr, idx + 1, k, ans, curr))
    {
        return true;
    }

    // take
    ans.push_back(arr[idx]);
    if (printsubseq(arr, idx + 1, k, ans, curr + arr[idx]))
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 6;
    vector<int> ans;
    printsubseq(arr, 0, k, ans, 0);
}