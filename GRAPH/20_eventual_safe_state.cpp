#include<bits/stdc++.h>
using namespace std;

/*


There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


*/


/*

    Can also apply TopologicalSort ..
    Reverse All the edges , Now apply BFS;Kahn's or DFS toposort... [if we want to print terminating node , just before nodes terminating , just just before terminating node....... so on] (thats the reason for reversing all edges)


*/

class Solution {
public:

    vector<int> ans;
    bool dfs(int node , vector<int> &vis ,vector<vector<int>> &graph)
    {
         vis[node] = 2;
         if(!graph[node].empty())
         {
            for(auto i : graph[node])
            {
                if(vis[i] == 2)
                {
                    return true;   // Cycle Detected
                }
                else if(vis[i] == 0)
                {
                    if(dfs(i , vis , graph) == true)
                    {
                        return true;        
                        /*
                         Path that is cyclic will never go down , 
                         So those Vertext that are in cycle will always remain 2.
                         So after traversing all we can identify which are in cycle or which not.
                         So vis[i]==1 are those whose path terminates.
                        */
                    }
                }
            } 
        }
        vis[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n , 0);
       
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
               dfs(i , vis , graph);
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
