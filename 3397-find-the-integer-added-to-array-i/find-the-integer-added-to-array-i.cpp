class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        // find highest in nums1
        int h1=nums1[0];
        for(auto it:nums1){
            if(h1>it)
                h1=it;
        }
        // find highest in nums2
        int h2=nums2[0];
        for(auto it:nums2){
            if(h2>it)
                h2=it;
        }
        return h2-h1;
    }
};