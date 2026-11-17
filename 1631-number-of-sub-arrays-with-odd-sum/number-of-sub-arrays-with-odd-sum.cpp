class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n =arr.size();
        int ans=0;
        long long even=1;
        long long odd=0;
        int mod=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                even++;
                ans=(ans+odd) % mod;
            }
            else{
                odd++;
                ans=(ans+even) % mod;
            }
        }
        return ans;
    }
};