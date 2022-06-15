#include <bits/stdc++.h>
using namespace std;

/*
#Important
*/
void Stock_Span(int arr[])
{
    int n = 6;
    stack<int> s;
    s.push(0);
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << i + 1 << " ";
        }
        else
        {
            cout << abs(i - s.top()) << " ";
        }
        s.push(i);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {18, 12, 13, 14, 11, 16};
    Stock_Span(arr);
    return 0;
}