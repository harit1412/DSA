#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {10, 20, 30};
    int n = 3;

    int temp = a[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }

        if ((a[i] != a[i - 1]) || i == n - 1)
        {
            cout << temp << " : " << count << endl;
            temp = a[i];
            count = 1;
        }
    }
}