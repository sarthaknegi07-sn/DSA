class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        // count no of even and odds
        int even=0;
        int odd=0;
        
        for(int it:nums){
            if(it % 2==0)
                even++;
            else
                odd++;
        }

        vector<int>res;
        for(int i=0;i<even;i++){
            res.push_back(0);
        }
        for(int i=0;i<odd;i++){
            res.push_back(1);
        }

        return res;
    }
};