class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& vis,int n){
        vis[node]=1;
        for(int j=0;j<n;j++){
            if(isConnected[node][j]==1 && !vis[j])
                dfs(j,isConnected,vis,n);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int province=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                province++;
                dfs(i,isConnected,vis,n);
            }
        }
        return province;
    }
};