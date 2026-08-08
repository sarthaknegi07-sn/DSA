class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int vis[m][n];
        // {{r,c},t}
        queue<pair< pair<int,int>, int>>q;
        
        int cntfresh=0;
        // first make visited array
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else 
                    vis[i][j]=0;
                if(grid[i][j]==1)   // this means the apple is fresh
                    cntfresh++;
            }
        }
        // now as the first rotten is pushed in queue
        int tm=0; 
        // for checking the adjacency apples
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();

            tm=max(t,tm);
            for(int i=0;i<4;i++){   // going to all 4 directions
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                // now check if the apple is not out of bound, not visited and a fresh apple
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        // check whether all fresh apples are rotten
        if(cntfresh!=cnt)
            return -1;
        return tm;
    }
};