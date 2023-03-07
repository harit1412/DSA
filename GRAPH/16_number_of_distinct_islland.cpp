#include <bits/stdc++.h>
using namespace std;

/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we
have only 1 distinct island.



1 1 0 1 1
1 0 0 0 1 
1 0 0 0 1
0 0 0 0 0

corect ans = 2;

*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/*
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

class Solution {
  public:
    vector<pair<int,int>> bfs(int i , int j , vector<vector<int>> &g)
    {
        int n = g.size();
        int m = g[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> pattern;
        q.push({i,j});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
           
            if(x >= 0 and y >= 0 and x < n and y < m and g[x][y] == 1 )
            {
                g[x][y] = 0;
                pattern.push_back({i-x , j-y});
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
            q.pop();
        }
        
      
        return pattern;
    }
    
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m  = grid[0].size();
        set<vector<pair<int,int>>> s;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<pair<int,int>> v = bfs(i,j,grid);
                    s.insert(v);
                }
            }
        }
        return s.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends