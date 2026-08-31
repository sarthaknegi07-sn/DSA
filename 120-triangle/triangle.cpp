class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& triangle){
        int n=triangle.size();
        // base case
        if(i==n-1)  // reached the last row
            return triangle[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int down=triangle[i][j] + fn(i+1,j,dp,triangle);
        int diag=triangle[i][j] + fn(i+1,j+1,dp,triangle);

        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //  TABULATION METHOD 
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        // base case
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j] + dp[i+1][j];
                int diag=triangle[i][j] + dp[i+1][j+1];

                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};