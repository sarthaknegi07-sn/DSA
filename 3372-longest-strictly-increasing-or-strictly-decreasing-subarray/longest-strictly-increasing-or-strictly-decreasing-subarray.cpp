class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        // first find the longest increasing length
        int maxlen=1;
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])
                len++;
            else{
                maxlen=max(maxlen,len);
                len=1;
            }
        }
        maxlen=max(maxlen,len);

        // find decreasing one
        len=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                len++;
            else{
                maxlen=max(maxlen,len);
                len=1;
            }
        }
        maxlen=max(maxlen,len);

        return maxlen;
    }
};