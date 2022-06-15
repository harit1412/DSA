#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {7, 10, 4, 10, 6, 5, 2};

    int n = v.size();
    int led = v.at(n - 1);
    cout << led << " ";
    for (int i = (n - 2); i >= 0; i--)
    {

        // cout << v.at(i) << " " << led << endl;
        // cout << led << " ";
        if (v.at(i) > led)
        {
            led = v.at(i);
            cout << led << " ";
        }
    }
}