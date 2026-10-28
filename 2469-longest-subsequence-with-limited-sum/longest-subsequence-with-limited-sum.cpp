class Solution {
public:
    int fn(vector<int>& nums,int sum){
        int l=0;
        long long s=0;
        int maxlen=0;
        for(int r=0;r<nums.size();r++){
            s+=nums[r];
            if(s<=sum){
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            else{
                s-=nums[l];
                l++;
            }
        }
        return maxlen;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            ans.push_back(fn(nums,queries[i]));
        }
        return ans;
    }
};