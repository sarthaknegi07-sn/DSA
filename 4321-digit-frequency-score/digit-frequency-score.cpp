class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>hash(10,0);
        int x=n;
        while(x!=0){
            int ans=x%10;
            x=x/10;
            hash[ans]++;
        }
        int sum=0;
        for(int i=1;i<=9;i++){
            sum+=hash[i]*i;
        }
        return sum;
    }
};