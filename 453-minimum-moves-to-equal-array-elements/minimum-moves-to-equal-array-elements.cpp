class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        int cnt=0;
        int minEle=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            cnt+=nums[i]-minEle;
        }
        return cnt;
    }
};