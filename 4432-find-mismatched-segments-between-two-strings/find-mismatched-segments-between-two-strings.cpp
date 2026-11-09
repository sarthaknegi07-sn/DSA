class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string >>ans;
        int n =s1.size();

        int i=0;
        while(i<n){
            string a="";
            string b="";
            while(s1[i]!=s2[i]){
                a+=s1[i];
                b+=s2[i];
                i++;
            }
            if(!a.empty())
                ans.push_back({a,b});
            i++;
        }
        return ans;
    }
};