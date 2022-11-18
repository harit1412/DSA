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
            bfs__(g, i, vis);
    }
}

void edge(vector<int> g[], int s, int d)
{
    g[s].push_back(d);
    g[d].push_back(s);
}
int main()
{

    vector<int> g[7];
    edge(g, 0, 1);
    edge(g, 0, 2);
    edge(g, 1, 3);
    edge(g, 2, 3);
    edge(g, 4, 5);
    edge(g, 4, 6);
    edge(g, 5, 6);

    // bfs(g, 0);
    bfs2(g, 7);
    return 0;
}