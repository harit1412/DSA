#include <bits/stdc++.h>
#define ll long long
using namespace std;
// const ll n = 1e5;
// vector<ll> v[n + 1];
// vector<bool> vis(n + 1);

vector<vector<char>> g;
bool vis[500][500];
void dfs(int i, int j)
{
    if (i >= 0 and i < g.size() and j >= 0 and j < g[0].size())
    {
        if (g[i][j] == '1' and !vis[i][j])
        {
            vis[i][j] = true;
            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    if (m == n and n == 0)
                        continue;
                    if (i + m >= 0 and i + m < g.size() and j + n >= 0 and j + n < g[0].size())
                        dfs(i + m, j + n);
                }
            }
        }
    }
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int m = -1; m <= 1; m++)
        {
            for (int n = -1; n <= 1; n++)
            {
                if (a + m >= 0 and a + m < g.size() and b + n >= 0 and b + n < g[0].size())
                {
                    if (m == n and m == 0)
                    {
                    }
                    else
                    {
                        if (!vis[a + m][b + n] and g[a + m][b + n] == '1')
                        {
                            vis[a + m][b + n] = true;
                            q.push({a + m, b + n});
                        }
                    }
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    g = grid;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and grid[i][j] == '1')
            {
                // cout << i << " " << j << endl;
                ans++;
                // dfs(i, j);
                bfs(i, j);
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<char> tm;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            tm.push_back(c);
        }
        ans.push_back(tm);
    }
    cout << numIslands(ans);
}