#include<bits/stdc++.h>
using namespace std;

// int lccm(int a , int b)
// {
//         int ans = 1;
//     for (int i = 2; i < max(a,b); i++)
//     {
//         if(a == 1 && b == 1)
//             break;
//         if( b%i == 0)
//         {
//             ans *= i;
//             b /= i;
//         }
//         if(a%i == 0 )
//         {
//             ans *= i;
//             a/=i;
//         }
//     }
//     return ans;
// }


int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
        int ans = 1;
        int res = max(a,b);

        for (int i = 2; i <= res; i++)
        {
            if (a == 1 && b == 1)
                break;
            if (b % i == 0)
            {
                ans *= i;
                b /= i;
                // cout << i << " ";
            }
            if (a % i == 0)
            {
                ans *= i;
                a /= i;
                // cout << i << " ";    
        }
    }
    cout << ans << endl;
    return 0;
}
