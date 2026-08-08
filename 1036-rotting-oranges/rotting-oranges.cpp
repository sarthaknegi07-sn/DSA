class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int vis[m][n];
        // {{r,c},t}
        queue<pair< pair<int,int>, int>>q;
        
        // first make visited array
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else 
                    vis[i][j]=0;
            }
        }
        // now the first rotten is pushed in queue
        int tm=0; 
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();

            tm=max(t,tm);
            for(int i=0;i<4;i++){   // going to all 4 directions
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                // now check if it is not out of bound, not visited and fresh
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        // check whether some apples aren't rotten
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                    return -1;
            }
        }
        return tm;
    }
};