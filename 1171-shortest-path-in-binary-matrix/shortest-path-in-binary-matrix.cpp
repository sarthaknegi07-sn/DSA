class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({{0,0},1});
        vis[0][0]=1;

        int delrow[]={-1,-1,0,1,1,1,0,-1};
        int delcol[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(i==n-1 && j==m-1){
                return dist;
            }
            for(int k=0;k<8;k++){
                int ith=i+delrow[k];
                int jth=j+delcol[k];
                if(ith>=0 && ith<n && jth>=0 && jth<m){
                    if(grid[ith][jth]==0 && vis[ith][jth]!=1){
                        vis[ith][jth]=1;
                        q.push({{ith,jth},dist+1});
                    }
                }
            }
        }
        return -1;
    }
};