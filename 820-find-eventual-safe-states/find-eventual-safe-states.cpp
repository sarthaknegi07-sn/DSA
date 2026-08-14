class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        unordered_set<int>st;

        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){  // terminal node push into ans and into set
                ans.push_back(i);
                st.insert(i);
            }
        }

        // now check if it already exists in set
        while(1){
            bool changed=false;
            for(int i=0;i<graph.size();i++){
                if(st.find(i)!=st.end())    // already present in set 
                    continue;

                bool safe=true;
                for(auto it:graph[i]){
                    if(st.find(it)==st.end()){  // got one node which is not safe
                        safe=false;
                        break;
                    }
                }
                if(safe){
                    ans.push_back(i);
                    st.insert(i);
                    changed=true;
                }
            }
            if(!changed)
                break;
        }

        // now sort ans
        sort(ans.begin(),ans.end());
        return ans;
    }
};