//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node , vector<int> &vis , vector<int> adj[])
    {
        vis[node] = 2;            // While Entering node set vis = 2 , to ensure same path.
        for(auto i : adj[node])
        {
            if(vis[i] == 2)
            {
                return true;
            }
            else if(vis[i] == 0)
            {
                if(dfs(i , vis , adj) == true)
                {
                    return true;
                }
            }
        }
        vis[node] = 1;  //  Now it's returing back from the whole path so now we can set it to 2
                        //  It will never visit again because alll vertices of components has been visited
        return false;              
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i] and dfs(i , vis , adj) == true)
            {
                return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t=1;
    // cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends