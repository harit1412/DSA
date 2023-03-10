//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void dfs(int node, vector<bool> &vis , stack<int> &st ,vector<pair<int,int>> adj[])
    {
        vis[node] = true;
        for(auto i : adj[node])
        {
            if(!vis[i.first])
            {
                dfs(i.first , vis,st , adj);
            }
        }
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto i : edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        stack<int> st;
        vector<bool> vis(N,false);
        for(int i = 0; i < N ; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }
        vector<int> dist(N , INT_MAX);
        dist[0] = 0;
        // Want to start from 0...
        while(st.top() != 0)
        {
            dist[st.top()] = -1;
            st.pop();
        }
        while(!st.empty())
        {
            int curr = st.top();
            for(auto i : adj[curr])
            {
                dist[i.first] = min(dist[i.first] , dist[curr]+i.second);
            }
            st.pop();
        }
        
      
        
        return dist;
        
        // return {};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends