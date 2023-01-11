#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
int main()
{
    //    for(int i = 0 ; i <= 11 ; i++)
    // cout << fibo(9,dp) << " ";
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << a+b;
    dp[0] = 0;
    dp[1] = 1;
    // for (int i = 2; i < n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << endl;
    // }

    /*
        space complexity O(1);
    */
    int a = 0;
    int b = 1;
    // // int sum = a+b;
    for (int i = 2; i < n; i++)
    {
        int sum = a + b;
        a = b;
        b = sum;
    }
    cout << a + b;
    // cout << dp[n-1];
}