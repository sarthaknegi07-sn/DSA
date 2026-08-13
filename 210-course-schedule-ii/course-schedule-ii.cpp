class Solution {
public:

    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj,vector<int>& ans){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj,ans)==true)   // cycle exists
                    return true;
            }
            // visited 
            else if(pathvis[it])    //cycle exists
                return true;
        }

        pathvis[node]=0;
        ans.push_back(node);
        return false;   // no cycle
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // check if a cycle exists in a directed graph
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<int>ans;

        // now make adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // now perform dfs
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,ans)==true)    // cycle exists
                    return {};
            }
        }
        // if cycle not exists then true!
        reverse(ans.begin(),ans.end());
        return ans;
    }
};