class Solution {
public:
    int fn(int ind,int sum,int target,vector<int>&nums){
        if(ind==nums.size()){
            if(sum==target)
                return 1;
            return 0;
        }

        int plus=fn(ind+1,sum+nums[ind],target,nums);
        int minus=fn(ind+1,sum-nums[ind],target,nums);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return fn(0,0,target,nums);
    }
};