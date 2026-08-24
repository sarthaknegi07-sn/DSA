class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        // 1st iterration to find the smaller ones
        for(auto it:nums){
            if(it<pivot)
                ans.push_back(it);
        }
        // 2nd iterration to find the equal ones
        for(auto it:nums){
            if(it==pivot)
                ans.push_back(it);
        }
        // 3rd iterration to find the greater ones
        for(auto it:nums){
            if(it>pivot)
                ans.push_back(it);
        }
        return ans;
    }
};