class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n =nums.size();
        int cnt=0;
        int midian=0;

        sort(nums.begin(),nums.end());
        if(n%2==0)
            midian=(nums[n/2]+nums[(n/2)-1]) / 2;
        else
            midian=nums[n/2];

        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-midian);
        }
        return cnt;
    }
};