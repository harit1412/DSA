#include<bits/stdc++.h>
using namespace std;
/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

*/

/*

Input: mat = [[0,0,0],
              [0,1,0],
              [1,1,1]]

Output: [[0,0,0],
        [0,1,0],
        [1,2,1]]

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            if(i+1 < n)
            {
                if(ans[i+1][j]==-1)
                {
                    q.push({i+1 ,j});
                    ans[i+1][j] = ans[i][j] + 1;
                }
            }
            if(i-1 >= 0)
            {
                if(ans[i-1][j] == -1)
                {
                    q.push({i-1 , j});
                    ans[i-1][j] = ans[i][j]+1;
                }
            }
            if(j+1 < m)
            {
                if(ans[i][j+1] == -1)
                {
                    q.push({i,j+1});
                    ans[i][j+1] = ans[i][j]+1;
                }
            }
            if(j-1 >= 0)
            {
                if(ans[i][j-1] == -1)
                {
                    q.push({i,j-1});
                    ans[i][j-1] = ans[i][j]+1;
                }
            }
            q.pop();
        }

        return ans;
    }

};
