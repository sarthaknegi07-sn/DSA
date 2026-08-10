class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                dfs(nrow,ncol,vis,grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // TRAVERSE THE BOUNDARIES
        // 1st row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,vis,grid);
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,vis,grid);
        }
        // 1st col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,vis,grid);
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,vis,grid);
        }

        // NOW TRAVERSE AND CHECK WHICH ALL ARE NOT VISITED AND ARE 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    ans++;
            }
        }
        return ans;
    }
};