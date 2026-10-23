class Solution {
public:
    int signFunc(int x){
        if(x%2==0)
            return 1;
        else
            return -1;
    }
    int arraySign(vector<int>& nums) {
        int cnt0=0;
        int cntn=0; //negatives
        for(auto it:nums){
            if(it==0){
                cnt0=1;
                break;
            }
            if(it<0)
                cntn++;
        }
        if(cnt0!=0)
            return 0;
        return signFunc(cntn);
    }
};