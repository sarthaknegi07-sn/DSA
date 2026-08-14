class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // PERFORMING IT USING TOPO SORT

        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // Now perform topo sort and if topo.size() == N -> cycle doesn't exists

        queue<int>q;

        // first find indegree
        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        // insert into q with indegree=0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            // now node is in your topo sort so remove it from the indegree
            for(auto it :adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(topo.size() == numCourses)
            return true;
        return false;
    }
};