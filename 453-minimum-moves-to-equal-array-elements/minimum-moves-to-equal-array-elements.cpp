class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end(),greater<int>()); // sorted in descending order
        int minEle=nums[n-1];
        for(int i=0;i<n-1;i++){
            cnt+=nums[i]-minEle;
        }
        return cnt;
    }
};