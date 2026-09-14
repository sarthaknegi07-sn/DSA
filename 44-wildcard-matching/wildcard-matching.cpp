class Solution {
public:
    int fn(int i,int j,string& p,string& s,vector<vector<int>>& dp){
        if(i<0 && j<0)  // both are exhausted
            return true;
        if(i<0 && j>=0) // pattern is over but string is remaining
            return false;

        // pattern is left but string is empty so all chars in pattern must be *
        if(j<0 && i>=0)
        {
            for(int x=0;x<=i;x++){
                if(p[x]!='*')
                    return false;
            }
            return true;
        }

        if(dp[i][j]!=-1)    return dp[i][j];

        if(p[i]==s[j] || p[i]=='?')
            return dp[i][j]=fn(i-1,j-1,p,s,dp);
        else if(p[i]=='*')  // not take or take
            return dp[i][j]=fn(i-1,j,p,s,dp) || fn(i,j-1,p,s,dp);
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m =s.size();
        int n =p.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return fn(n-1,m-1,p,s,dp);
    }
};