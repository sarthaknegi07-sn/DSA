class Solution {
public:
    int fn(int ind,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>>& dp){
        int n=prices.size();

        if(ind==n)
            return 0;
        if(cnt>=2)
            return 0;
        if(dp[ind][buy][cnt]!=-1)
            return dp[ind][buy][cnt];

        int profit=0;   
        if(buy && cnt<2){
            profit=max(-prices[ind]+fn(ind+1,0,cnt,prices,dp),    // buying
                fn(ind+1,1,cnt,prices,dp)  // not buying
                );
        }
        else if(!buy && cnt<2){
            profit=max(prices[ind]+fn(ind+1,1,cnt+1,prices,dp),  // selling
                fn(ind+1,0,cnt,prices,dp)   //not selling
                );
        }

        return dp[ind][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return fn(0,1,0,prices,dp);
    }
};