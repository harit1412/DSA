#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int temp;
        for (int j = i + 1; j < n; j++)
        {
            if (v.at(j) > v.at(i))
            {
                flag = -1;
                break;
            }
        }
        if (flag == 0)
        {

            if (v.at(i) != temp)
                cout << v.at(i) << " ";
            temp = v.at(i);

        }
    }
}