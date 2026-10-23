class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n =nums.size();
        int sum=nums[0];
        int maxi=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(prev<nums[i])
                sum+=nums[i];

            else{
                maxi=max(maxi,sum);
                sum=0;
                sum+=nums[i];
            }   
            prev=nums[i];
        }
        maxi=max(maxi,sum);
        return maxi;
    }
};