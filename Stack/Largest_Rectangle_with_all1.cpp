#include <bits/stdc++.h>
using namespace std;

int MaxRec(int a[])
{
    int n = sizeof(a) / sizeof(a[0]);
    stack<int> s;
    vector<int> ls;
    s.push(0);
    ls.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] >= a[s.top()])
        {
            s.pop();
        }

        if (s.empty())
            ls.push_back(-1);
        else
            ls.push_back(s.top());
        s.push(i);
    }
    stack<int> st;
    s.push(n - 1);
    vector<int> ns;
    ns.push_back(n);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }

        if (s.empty())
            ns.push_back(-1);
        else
            ns.push_back(s.top());
        st.push(i);
    }
    reverse(ns.begin(), ns.end());

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int curr = a[i];
        curr += (i - ls[i] - 1)*a[i];
        curr += (ns[i] - i - 1)*a[i];

        if (curr > ans)
            ans = curr;
    }
    return ans;
}


// Similiar to Histogram .... Consider Collum as Histogram graph {Taking all level } ... Area will give Max 1, rec...


int main(int argc, char const *argv[])
{

    int mat[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
    };
    int max = 0;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mat[i][j])
                mat[i][j] += mat[i - 1][j];
        }
        if (max < MaxRec(mat[i]))
            max = MaxRec(mat[i]);
    }
    cout << max << endl;
    return 0;
}