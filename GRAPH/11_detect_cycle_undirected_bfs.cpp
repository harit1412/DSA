#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 1e5;
vector<ll> v[n + 1];
vector<bool> vis(n + 1);

bool detect_cycle_bfs(int node)
{
    queue<pair<int,int>> q;
    q.push({node,-1});
    vis[node] = true;
    while(!q.empty())
    {
        int par = q.front().second;
        for(auto i : v[q.front().first])
        {
            if(vis[i])
            {
                if(i != par)
                {
                    return true;
                }
            }
            else
            {
                vis[i] = true;
                q.push({i , q.front().first});
            }
        }
        q.pop();
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
    if(detect_cycle_bfs(1))cout << "Yes";
    else cout << "No";
}