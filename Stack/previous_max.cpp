#include <bits/stdc++.h>
using namespace std;
void PrintGreater(int a[])
{
    stack<int> s;
    s.push(0);
    cout << "-1 ";
    for (int i = 1; i < 5; i++)
    {
        while(!s.empty() && a[i] >= a[s.top()])
            s.pop();
        
        if(s.empty())
        {
            cout << "-1 ";
        }
        else
        {
            cout << a[s.top()] << " ";
        }
        s.push(i);
        
    }
}
int main(int argc, char const *argv[])
{
    int a[] = {20, 30, 10, 5, 15};
    PrintGreater(a);
    return 0;
}