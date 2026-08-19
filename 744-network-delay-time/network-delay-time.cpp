class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        pq.push({0,k});
        dist[k]=0;
        
        // MAKE ADJACENCY LIST :
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
        }

        while(!pq.empty()){
            int node=pq.top().second;
            int time=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                int n=it.first;
                int t=it.second;
                if(time+t < dist[n]){
                    dist[n]=time+t;
                    pq.push({dist[n],n});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};