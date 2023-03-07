#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool vis[500][500]={false};
    vector<vector<int>> g;
    int n,m;
    void  dfs(int i , int j)
    {
        if(i >= 0  and j >= 0 and i < n and j < m and g[i][j] == 1 and !vis[i][j])
        {
            vis[i][j] = true;
            dfs(i+1 , j);
            dfs(i-1 , j);
            dfs(i , j+1);
            dfs(i , j-1);
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        g = board;
        for(int i = 0 ; i < n ; i++)
        {
            if(g[i][0] == 1 and !vis[i][0])
            {
                dfs(i,0);
            }
            if(g[i][m-1] == 1 and !vis[i][m-1])
            {
                dfs(i,m-1);
            }
        }

        for(int i = 0 ; i < m ; i++)
        {
            if(g[0][i] == 1 and !vis[0][i])
            {
                dfs(0,i);
            }
            if(g[n-1][i] == 1 and !vis[n-1][i])
            {
                dfs(n-1,i);
            }
        }
    int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(!vis[i][j] and g[i][j]==1)
                {
                    count++;
                }
            }
            // cout << endl;
        }
        return count;
    }
};