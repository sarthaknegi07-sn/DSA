class Solution {
public:
    bool subsetsumtok(int ind ,int target ,vector<vector<int>>& dp,vector<int>& nums){
        if(target==0)   return true;
        if(ind==0)  return (target==nums[0]);
        if(dp[ind][target]!=-1) 
            return dp[ind][target];

        bool nottake=subsetsumtok(ind-1,target,dp,nums);
        bool take=false;
        if(target>=nums[ind])
            take=subsetsumtok(ind-1,target-nums[ind],dp,nums);
        
        return dp[ind][target] = take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        // 1 simple approach is to find only 1 subset with sum = total sum / 2
        // if the subset exists then -> true    else -> false;

        // first find the total sum
        int sum=0;
        for(int it:nums)
            sum+=it;
        
        if(sum % 2 != 0)    // odd
            return false;

        // now find the subset with half sum
        int n =nums.size();
        int k=sum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        return subsetsumtok(n-1,k,dp,nums);
    }
};