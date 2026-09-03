class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;boxes[i]!='\0';i++){
            int sum=0;
            for(int j=0;boxes[j]!='\0';j++){
                if(boxes[j]=='1')
                    sum+=abs(i-j);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};