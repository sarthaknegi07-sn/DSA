class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxu(n);
        vector<int> minu(n);

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            maxu[i] = maxi;
        }

        int mini = INT_MAX;

        for(int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            minu[i] = mini;
        }

        for(int i = 0; i < n; i++) {
            int score = maxu[i] - minu[i];

            if(score <= k)
                return i;
        }

        return -1;
    }
};