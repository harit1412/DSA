//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool dfs(int node , vector<int> &col ,vector<int>adj[])
    {
        for(auto i : adj[node])
        {
            if(col[i]==-1)
            {
                col[i] = !col[node];
                if(dfs(i,col,adj) == false)
                {
                    return false;
                }
            }
            else
            {
                if(col[i] == col[node])
                {
                    return false;
                }
            }
            
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(col[i] == -1)
	        {
	            col[i] = 0;
	            if(!dfs(i,col,adj))return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends