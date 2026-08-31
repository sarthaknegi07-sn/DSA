class Solution {
public:
    int posspaths(int i,int j,vector<vector<int>>& dp){
        // BASE CASES
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int up=posspaths(i-1,j,dp);
        int left=posspaths(i,j-1,dp);

        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return posspaths(m-1,n-1,dp);
    }
};