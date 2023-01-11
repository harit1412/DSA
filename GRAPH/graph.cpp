#include <bits/stdc++.h>
using namespace std;
bool visited[4] = {false};
void dfs(vector<int> g[], int s)
{
    if (!visited[s])
    {
        cout << s << " ";
        visited[s] = true;
        for (auto i : g[s])
        {
            dfs(g, i);
        }
    }
}

void dfs__(vector<int> g[], int s, bool vis[])
{
    if (!vis[s])
    {
        cout << s << " ";
        vis[s] = true;
        for (auto i : g[s])
        {
            dfs__(g, i, vis);
        }
    }
}
void dfs2(vector<int> g[], int n) // n -> total node
{
    bool vis[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs__(g, i, vis);
            // count++;    /* For counting connected component */
        }
    }
}

// With Given Source
void bfs(vector<int> g[], int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (visited[curr] == true)
        {
            continue;
        }
        visited[curr] = true;
        cout << curr << " ";
        for (auto i : g[curr])
        {
            q.push(i);
        }

        // Another way ...
        /*
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            cout << curr << " ";
            for(auto i : g[curr])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        */
    }
}

// Without source {A node which is disconnected from graph will also be printed}
void bfs__(vector<int> g[], int s, bool vis[])
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        vis[curr] = true;
        cout << curr << " ";
        for (auto i : g[curr])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}
void bfs2(vector<int> g[], int n) // n -> total node
{
    bool vis[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            bfs__(g, i, vis); // , count++ ; /* to count total number of connnected componene */
    }
}

void edge(vector<int> g[], int s, int d)
{
    g[s].push_back(d);
    // g[d].push_back(s);
}

// Shortest Path in the unweighted  graph

void Short_Unweighted(vector<int> g[], int s, int n)
{
    vector<int> dis(n, INT_MAX);
    bool vis[n] = {false};
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        vis[curr] = true;
        for (auto i : g[curr])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
                dis[i] = dis[curr] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
}

// Detect Cycle in undirected...

// Using DFS ...

bool dfs_cycle(vector<int> g[], int s, bool vis[], int par)
{
    vis[s] = true;
    for (auto i : g[s])
    {
        if (!vis[i])
        {
            if (dfs_cycle(g, i, vis, s))
                return true;
        }
        else if (i != par)
        {
            return true;
        }
    }
    return false;
}

bool IsCycle(vector<int> g[], int n)
{
    bool vis[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs_cycle(g, i, vis, -1))
            {
                return true;
            }
        }
    }
    return false;
}

bool bfs_cycle(vector<int> g[], int s, bool vis[], int n)
{
    vector<int> par(n, -1);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto i : g[curr])
        {
            if (!vis[i])
            {
                par[i] = curr;
                vis[i] = true;
                q.push(i);
            }
            else if (curr != par[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool IsCycle2(vector<int> g[], int n)
{
    bool vis[n] = {false};
    // int par[n] = {-1};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] and bfs_cycle(g, i, vis, n))
            return true;
    }
    return false;
}

// Detect Cycle in direct edge ...

bool dir_cycle(vector<int> v[], int s, vector<bool> &vis, vector<bool> &rec)
{
    vis[s] = true;
    rec[s] = true;
    for (auto i : v[s])
    {
        if (!vis[i])
        {
            if(dir_cycle(v, i, vis, rec))
            {
                return true;
            }   
        }
        else if (rec[i])
        {
            return true;
        }
    }
    rec[s] = false;
    return false;
}

int main()
{
    int n = 4;
    vector<int> g[n];
    edge(g, 0, 1);
    edge(g, 1, 2);
    edge(g, 2, 0);
    edge(g, 2, 3);

    vector<bool> vis(n, false);
    vector<bool> rec(n, false);

    // bool ans = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!vis[i])
    //         ans |= dir_cycle(g, i, vis, rec);
    // }
    // cout << ans;.


    return 0;
}




