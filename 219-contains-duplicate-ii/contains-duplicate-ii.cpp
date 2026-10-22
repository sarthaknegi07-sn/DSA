class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto itf:mp){
            int it=itf.first;
            int x=mp[it].size();
            if(x<=1)
                continue;
            
            for(int j=0;j<x-1;j++){
                if(abs(mp[it][j]-mp[it][j+1])<=k)
                    return true;
            }
        }
        return false;

    }
};