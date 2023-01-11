#include <bits/stdc++.h>
#define long long ll
using namespace std;
void printsubseq(vector<int> arr, int idx, int k, vector<int> ans, int curr)
{
    if (idx == arr.size())  // {1,2,3,4,5,0}
    {
        if (curr == k)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return;
        }
        return;
    }
    printsubseq(arr, idx + 1, k, ans, curr);
    ans.push_back(arr[idx]);
    printsubseq(arr, idx + 1, k, ans, curr + arr[idx]);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 0};
    int k = 6;
    vector<int> ans;
    printsubseq(arr, 0, k, ans, 0);
}