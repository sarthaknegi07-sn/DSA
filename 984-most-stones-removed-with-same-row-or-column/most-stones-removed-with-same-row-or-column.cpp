class DisJointSet {
public:
    vector<int>rank,parent;
    DisJointSet (int n ){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)    return ;
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v])
            parent[ulp_v]=ulp_u;
        else{   // same so increase rank
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        // first count maxcol and maxrow
        int maxcol=0,maxrow=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisJointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=maxrow+1+it[1];
            ds.UnionByRank(noderow,nodecol);
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }
        // now count connected components
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first)
                cnt++;
        }
        return n-cnt;
    }
};