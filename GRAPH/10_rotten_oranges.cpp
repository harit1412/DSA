#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int curr_size = q.size();
            for (int i = 0; i < curr_size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                if (r + 1 < n and grid[r + 1][c] == 1)
                {
                    fresh--;
                    grid[r + 1][c] = 2; // In BFS always change while pushing into queue
                    q.push({r + 1, c});
                }
                if (r - 1 >= 0 and grid[r - 1][c] == 1)
                {
                    fresh--;
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                }
                if (c + 1 < m and grid[r][c + 1] == 1)
                {
                    fresh--;
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                }
                if (c - 1 >= 0 and grid[r][c - 1] == 1)
                {
                    fresh--;
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                }
                q.pop();
            }
            if (!q.empty())
            {
                count++;
            }
        }
        if (fresh)
            return -1;
        return count;
    }
};