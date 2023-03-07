#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll n = 1e5;
vector<ll> v[n + 1];
vector<bool> vis(n + 1);

void dfs(int node)
{
    vis[node] = true;
    for(auto i : v[node])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}

int compo(int n)
{
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i);
        }
    }
    return count;
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

    cout << compo(n);
}