class Solution {
public:
    bool pal(string str){
        int n =str.size();
        int i=0,j=n-1;
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++,j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words){
            if(pal(it))
                return it;
        }
        return "";
    }
};