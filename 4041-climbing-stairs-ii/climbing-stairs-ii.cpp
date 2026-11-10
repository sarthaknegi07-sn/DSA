class Solution {
public:
    int solve(int i,vector<int>& costs,vector<int> &dp){
        int n =costs.size();
        if(i==n)
            return 0;
            
        if(dp[i]!=0)
            return dp[i];
        int cost=1e9;
        for(int j=i+1;j<=min(i+3,n);j++){
            cost=min(cost,(j-i)*(j-i) +costs[j-1]+solve(j,costs,dp));
        }
        return dp[i]=cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
        return solve (0,costs,dp);
    }
};