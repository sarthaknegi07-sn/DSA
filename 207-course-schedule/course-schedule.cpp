class Solution {
public:

    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)==true)   // cycle exists
                    return true;
            }
            // visited 
            else if(pathvis[it])
                return true;
        }

        pathvis[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // check if a cycle exists in a directed graph
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);

        // now make adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // now perform dfs
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)==true)    // cycle exists
                    return false;
            }
        }
        // if cycle not exists then true!
        return true;
    }
};