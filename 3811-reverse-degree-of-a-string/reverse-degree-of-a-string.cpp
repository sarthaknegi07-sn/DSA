class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        int temp=26;
        for(char ch='a';ch<='z';ch++){
            mp[ch]=temp--;
        }

        for(int i=1;s[i-1]!='\0';i++){
            ans+=i*mp[s[i-1]];
        }
        return ans;
    }
};