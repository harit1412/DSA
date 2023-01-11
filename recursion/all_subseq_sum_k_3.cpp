#include <bits/stdc++.h>
#define long long ll
using namespace std;

// Count number of sequences

int printsubseq(vector<int> arr, int idx, int k,  int curr)  // no need to carry "ans vector";
{
    // if(curr > k)   // only can be done if all elements are positives   
    // {
    //     return;
    // }
    if (idx == arr.size())
    {
        if (curr == k)
        {
            return 1;
        }
        return 0;
    }

    int not_take = printsubseq(arr, idx + 1, k,  curr);
    int take = printsubseq(arr, idx + 1, k, curr + arr[idx]);
    return take + not_take;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5,0};
    int k = 6;
    vector<int> ans;
    cout << printsubseq(arr, 0, k, 0);
}