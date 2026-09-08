class Solution {
public:
    int fn (int ind ,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(amt==0)
            return 1;
        if(ind==0){
            if(amt % coins[ind] == 0)   return 1;
            return 0;
        }
        if(dp[ind][amt]!=-1)    return dp[ind][amt];

        int nottake=fn(ind-1,amt,coins,dp);
        int take=0;
        if(coins[ind]<=amt){
            take=fn(ind,amt-coins[ind],coins,dp);
        }

        return dp[ind][amt]= take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=fn(coins.size()-1,amount,coins,dp);
        return ans;
    }
};