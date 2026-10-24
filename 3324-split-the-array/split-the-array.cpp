class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int freq[101]={0};
        int n =nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>2)
                return false;
        }
        return true;
    }
};