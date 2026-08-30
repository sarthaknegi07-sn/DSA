class Solution {
public:
    int power(long long x,long long y){
        const long long MOD = 1000000007;
    long long ans = 1;

    while(y > 0) {

        if(y % 2 == 1) {
            ans = (ans * x) % MOD;
        }

        x = (x * x) % MOD;
        y = y / 2;
    }

    return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum=0;
        for(auto it :nums){
            long long w=it%10;
            long long d=it/10;
            // calculate size of p
            long long temp=d;
            long long p=1;
            while(temp>=10){
                p=p*10;
                temp=temp/10;
            }
            for(long long i = 1; i < w; i++){
                p /= 10;
            }
            long long x=d/p;
            long long y=d%p;
            sum = (sum + power(x,y)) % 1000000007;
        }
        return sum;
    }
};