class Solution {
private:
    int timer=1;
    void dfs(int node ,int parent, vector<int>adj[],int tin[],int low[],vector<int>&vis,vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        // now traverse its adjacent nodes 
        for(auto it:adj[node]){
            if(it==parent)  // if current node is parent node 
                continue;
            if(vis[it]==0){   // NOT VISITED
                dfs(it,node,adj,tin,low,vis,bridges);
                low[node]=min(low[node],low[it]);   // take the minimum
                // check can this node --> it be a bridge
                if(low[it] > tin[node])
                    bridges.push_back({it,node});
            }
            else{   // VISITED
                low[node]=min(low[node],low[it]);   // take the minimum
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int tin[n]; // time of insertion
        int low[n]; // min lowest time insertion of all adjacent nodes apart from parent
        vector<vector<int>>bridges;
        dfs(0,-1,adj,tin,low,vis,bridges);
        return bridges;
    }
};