class Solution {
public:
    int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(sum == 0 && num[0] == 0)
                return 2;

            if(sum == 0 || sum == num[0])
                return 1;

            return 0;
        }

        if(dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = f(ind - 1, sum, num, dp);

        int take = 0;

        if(num[ind] <= sum)
            take = f(ind - 1, sum - num[ind], num, dp);

        return dp[ind][sum] = (notTake + take);
    }

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

        return f(n - 1, tar, num, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totSum = 0;

        for(auto &it : arr)
            totSum += it;

        if(totSum - d < 0 || (totSum - d) % 2)
            return 0;

        return findWays(arr, (totSum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};