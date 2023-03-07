//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution1
{
public:
    vector<vector<int>> im;
    vector<vector<bool>> vis;
    int color;
    void dfs(int i, int j)
    {

        vis[i][j] = true;
        if (i >= 0 and j >= 0 and i < im.size() and j < im[0].size())
        {
            int row[] = {1, -1, 0, 0};
            int col[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; k++)
            {
                int newRow = i + row[k];
                int newCol = j + col[k];

                if (newRow >= 0 and newCol >= 0 and newRow < im.size() and newCol < im[0].size())
                {
                    if (!vis[newRow][newCol] and im[newRow][newCol] == im[i][j])
                        dfs(newRow, newCol);
                }
            }
            im[i][j] = color;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here

        im = image;
        color = newColor;
        vector<vector<bool>> v(101, vector<bool>(101, false));
        vis = v;
        dfs(sr, sc);
        return im;
    }
};

class Solution2
{
public:
    // bool vis[51][51] = {true};
    void chk(vector<vector<int>> &img, int col, int i, int j, int x)
    {
        if (i >= 0 and j >= 0 and i < img.size() and j < img[i].size() and img[i][j] == x)
        {
            // vis[i][j] = true;
            img[i][j] = col;
            chk(img, col, i + 1, j, x);
            chk(img, col, i - 1, j, x);
            chk(img, col, i, j + 1, x);
            chk(img, col, i, j - 1, x);
        }
        else
        {
            return;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int x = image[sr][sc];
        if (x != color)
            chk(image, color, sr, sc, x); // this codintion is usefull when we do not use visited array
        return image;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution1 obj;
        Solution2 obj2;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends