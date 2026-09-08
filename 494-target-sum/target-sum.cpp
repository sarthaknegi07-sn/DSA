class Solution {
public:
    int fn(int ind,int sum,int target,vector<int>&nums,vector<vector<int>>& dp,int total){
        if(ind==nums.size()){
            if(sum==target)
                return 1;
            return 0;
        }
        if(dp[ind][sum+total]!=-1)    return dp[ind][sum+total];

        int plus=fn(ind+1,sum+nums[ind],target,nums,dp,total);
        int minus=fn(ind+1,sum-nums[ind],target,nums,dp,total);

        return dp[ind][sum+total]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // find total sum
        int total=0;
        for(int it:nums)
            total+=it;
        vector<vector<int>>dp(nums.size(),vector<int>(2*total+1,-1));
        return fn(0,0,target,nums,dp,total);
    }
};