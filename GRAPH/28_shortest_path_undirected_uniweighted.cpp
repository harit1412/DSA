//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*

  BFS do level order traversal ,
  If a node is already visited and try to visit again means that
  we are currently ahead of that level,
  going backwards always give bigger distance , so never update visited nodes.

*/

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(N, false);
        queue<int> q;
        q.push(src);
        vector<int> dist(N, -1);
        dist[src] = 0;
        vis[src] = true;
        while (!q.empty())
        {
            int curr = q.front();
            for (auto i : adj[curr])
            {
                if (!vis[i])
                {
                    vis[i] = true;
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
            q.pop();
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends