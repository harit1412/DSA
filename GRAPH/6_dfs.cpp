#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll n = 1e5;
vector<ll> v[n + 1];
vector<bool> vis(n + 1);

void dfs(int node)
{
    vis[node] = true;
    cout << node << " ";
    for(auto i : v[node])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}

void dfs2(int node)
{
    stack<int> s;
    s.push(node);
    vis[node] = true;
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << " ";
        for(auto i : v[curr])
        {
            if(!vis[i])
            {
                vis[i] = true;
                s.push(i);
            }    
        }
    }
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
    dfs(1);
    cout << endl;
    fill(vis.begin() , vis.end(),false);
    dfs2(1);
}