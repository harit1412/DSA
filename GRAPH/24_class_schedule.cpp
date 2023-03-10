#include<bits/stdc++.h>
using namespace std;

/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

class Solution {
public:

    bool dfs(int node , vector<int> &vis , vector<int> adj[])
    {
        vis[node] = 2;
        for(auto i : adj[node])
        {
            if(vis[i] == 2)
            {
                return false;
            }
            if(vis[i] == 0)
            {
                if(dfs(i,vis,adj) == false)
                {
                    return false;
                }
            }
        }
        vis[node] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            make graph of (bi -> ai) of all pre[i]

            Can be done in 2 ways , As we have to topoligcally sort , 
            graph of prerequirstiest must be acyclic.

            We can just check that given graph is cyclic or not ,
            
            Or 
            
            We can apply algorithm of topological sort and check it has
            given answer size is equal to total course or not. 
        */

        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        // Using DFS : 
        // We cant do the same , just see for [[0,1] , [1,0]]
        // We have to check using proper cycle check.
        vector<int> vis(numCourses , 0);

        for(int i = 0 ; i < numCourses ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj)==false)
                {
                    return false; // Contain Cycle
                }
            }
        }
        return true;






        // Using Kahns Algorithm (BFS)

        // Applying TopoLogical sort.

        // If there is multiple components(IN BFS only) , We never miss anyone , becuase each graph contain zero indegree node if not contain it must be cycle with three nodes , so it will always try to visit all node even there are diffrent components.
        queue<int> travs;
        queue<int> ans;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(indeg[i] == 0)
            {
                travs.push(i);
                ans.push(i);
            }
        }

        while(!travs.empty())
        {
            int curr = travs.front();
            for(auto i : adj[curr])
            {
                indeg[i]--;
                if(indeg[i] == 0)
                {
                    travs.push(i);
                    ans.push(i);
                }
            }
            travs.pop();
        }

        vector<int> anss;
        if(ans.size() == numCourses)
        {
            while(!ans.empty())
            {
                anss.push_back(ans.front());
                ans.pop();
            }
            return true;
        }
        return false;



    }
};