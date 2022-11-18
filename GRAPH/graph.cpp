#include <bits/stdc++.h>
using namespace std;
bool visited[6] = {false};
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

// With Given Source
void bfs(vector<int> g[], int s)
{
    queue<int> q;
    q.push(0);
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
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (vis[curr] == true)
        {
            continue;
        }
        vis[curr] = true;
        cout << curr << " ";
        for (auto i : g[curr])
        {
            q.push(i);
        }
    }
}
void bfs2(vector<int> g[], int n) // n -> total node
{
    bool vis[n] = {false};
    for (int i = 0; i < n; i++)
    {
        for (auto i : g[i])
        {
            if (!vis[i])
            {
                bfs__(g, i, vis);
            }
        }
    }
}



int main()
{
    vector<int> g[6];
    g[0].push_back(1);
    g[0].push_back(2);
    g[0].push_back(5);
    g[1].push_back(3);
    g[2].push_back(4);
    g[4].push_back(5);
    g[3].push_back(5);
    bfs2(g, 6);
    return 0;
}