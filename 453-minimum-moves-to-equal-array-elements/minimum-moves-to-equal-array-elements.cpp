class Solution {
public:
    bool fn(vector<int>& nums){
        int n =nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1])
                return true;
        }
        return false;
    }
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