class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n =nums.size();
        int maxlen=1;
        int l=0;
        for(int r=0;r<n-1;r++){
            if(nums[r]>=nums[r+1]){
                maxlen=max(maxlen,r-l+1);
                l=r+1;
            }
        }
        maxlen=max(maxlen,n-l);
        return maxlen;
    }
};