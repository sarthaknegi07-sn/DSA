class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>st;
        for(auto it:friends){
            st.insert(it);
        }
        vector<int>ans;
        for(auto it:order){
            if(st.find(it)!=st.end())
                ans.push_back(it);
        }
        return ans;
    }
};