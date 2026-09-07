class Solution {
public:
    int fn(int ind,int target,vector<int>& coins,vector<vector<int>> &dp){
        // BASE CASE
        if(ind==0){
            if(target % coins[ind] == 0)
                return target / coins[ind];
            else
                return INT_MAX;
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];


        int nottake=fn(ind-1,target,coins,dp);
        int take=INT_MAX;   //because we finding min so default should be max

        if(target >= coins[ind]){
            int x = fn(ind, target - coins[ind],coins,dp);

            if (x != INT_MAX)
               take = 1 + x;
        }

        return dp[ind][target] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,-1));
        int ans= fn(coins.size()-1,amount,coins,dp);

        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};