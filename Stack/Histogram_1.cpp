#include <bits/stdc++.h>
using namespace std;

void Area(int a[])
{
    int n = 7;
    stack<int> s;
    vector<int> v;
    // Presious Smaller
    v.push_back(-1);
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] <= a[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(s.top());
        }

        s.push(i);
    }
    stack<int> st;
    st.push(n - 1);
    vector<int> v1;
    v1.push_back(n);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            v1.push_back(n);
        }
        else
        {
            v1.push_back(st.top());
        }
        st.push(i);
    }
    reverse(v1.begin(), v1.end());

    int ans = 0;
    // for(auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto i : v1)
    // {
    //     cout << i << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        curr += (i - v[i] - 1) * a[i];
        curr += (v1[i] - i - 1) * a[i];
        ans = max(ans, curr);
    }

    cout << ans << endl;

    // return ans;
}

// Finding All next greater and Previous Elements . And finiding All
// elements Area accordingly using next greater and previous elements

int main(int argc, char const *args[])
{

    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    Area(arr);
    return 0;
}
