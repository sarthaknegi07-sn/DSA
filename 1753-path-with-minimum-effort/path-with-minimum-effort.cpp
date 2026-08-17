class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n =heights.size();
        int m =heights[0].size();

        priority_queue<pair<int, pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,1e9));

        pq.push({0,{0,0}});
        vis[0][0]=1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int ht=pq.top().first;
            pq.pop();

            if(i==n-1 && j==m-1)
                    return ht;

            for(int k=0;k<4;k++){
                int ith=i+delrow[k];
                int jth=j+delcol[k];

                if(ith>=0 && ith<n && jth>=0 && jth<m){
                    int neweffort=max(abs(heights[ith][jth]-heights[i][j]),ht);
                    // now check if in vis their is a large effort than neweffort
                    if(neweffort<vis[ith][jth]){
                        vis[ith][jth]=neweffort;
                        pq.push({neweffort,{ith,jth}});
                    }
                }
            }
        }return -1;
    }
};