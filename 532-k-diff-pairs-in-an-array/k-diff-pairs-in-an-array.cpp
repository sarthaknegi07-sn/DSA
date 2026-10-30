class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int m=nums.size();
        int cnt=0;
        vector<int>new1;
        sort(nums.begin(),nums.end());

        if(k == 0) {
            for(int i = 1; i < m; i++) {
                if(nums[i] == nums[i-1]) {
                    cnt++;
                    while(i < m && nums[i] == nums[i-1])
                        i++;
                }
            }
            return cnt;
        }

        for(int i=0;i<m;i++){
            if(i==0 || nums[i]!=nums[i-1])
                new1.push_back(nums[i]);
        }
        int n =new1.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(abs(new1[i]-new1[j])==k)
                    cnt++;
            }
        }
        return cnt; 
    }
};