#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 1e5;
vector<ll> v[n + 1];
vector<bool> vis(n + 1);

bool detect_cycle_dfs(int node, int par)
{
    vis[node] = true;
    for (auto i : v[node])
    {
        if (!vis[i])
        {
            if (detect_cycle_dfs(i, node))
            {
                return true;
            }
        }
        else
        {
            if (i != par)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (detect_cycle_dfs(1, -1))
        cout << "Yes";
    else
        cout << "No";
}