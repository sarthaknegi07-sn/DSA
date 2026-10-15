class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<int>st;
        for(char ch:s){
            if(ch=='('){
                st.push('(');
            }
            else{
                if(!st.empty())
                    st.pop();
                else{
                    cnt++;
                }
            }
        }
        cnt+=st.size();
        return cnt;
    }
};