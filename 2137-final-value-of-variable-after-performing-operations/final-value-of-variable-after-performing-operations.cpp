class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto s :operations){
            if(s=="--X" || s=="X--")
                ans-=1;
            else
                ans+=1;
        }
        return ans;
    }
};