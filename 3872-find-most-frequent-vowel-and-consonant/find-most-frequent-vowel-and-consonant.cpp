class Solution {
public:
    int maxFreqSum(string s) {
        int hash[26]={0};
        for(int i=0;s[i]!='\0';i++){
            hash[s[i]-'a']++;
        }
        int maxi=0;
        maxi=max(maxi,hash[0]);
        maxi=max(maxi,hash[4]);
        maxi=max(maxi,hash[8]);
        maxi=max(maxi,hash[14]);
        maxi=max(maxi,hash[20]);
        
        int ans=maxi;
        int max2=hash[1];
        int i=2;
        while(i<=25){
            if(i==4 || i==8 || i==14 || i==20){
                i++;
                continue;
            }
            max2=max(max2,hash[i]);
            i++;
        }

        ans+=max2;
        return ans ;
    }
};