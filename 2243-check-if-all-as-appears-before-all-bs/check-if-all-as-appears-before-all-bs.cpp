class Solution {
public:
    bool checkString(string s) {
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                ind=i;
                break;
            }
        }
        if(ind==-1)
            return true;
        for(int i=ind;i<s.size();i++){
            if(s[i]=='a')
                return false;
        }
        return true;
    }
};