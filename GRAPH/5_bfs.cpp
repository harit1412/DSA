#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll n = 1e5;
vector<ll> v[n + 1];
vector<bool> vis(n + 1);
void bfs(int node)
{
    queue<ll> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        // vis[curr] = true;   // Not correct if it is above..
        /*
            In this case , 5 is connected to 4 and 7 both , 4 and 7 will reach in queue before 5 .
            So if we set true above , then 5 will repeat.Because 4 will also add 5 into queue and 7 will
            add into queue.If we set true when entering the queue then 5 will not added twice. 
            Only one of 4 or 7 will add 5 into queue
        */  
        cout << curr << " ";
        for (auto i : v[curr])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
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
    bfs(1);
}