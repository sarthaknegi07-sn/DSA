class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";

        // 1st step find weight of words and store it in a vector
        vector<int>wt;
        for(int i=0;i<words.size();i++){
            int w=0;
            for(int j=0;j<words[i].size();j++){
                w+=weights[words[i][j]-'a'];
            }
            wt.push_back(w%26);
        }
        
        // first do mapping of all the alphabets
        unordered_map<int,char>mp;
        int i=25;
        for(char ch='a';ch<='z';ch++){
            mp[i--]=ch;
        }

        // now wt={8,17,16}
        int j=0;
        for(auto it:wt){
            res.push_back(mp[it]);
        }
        
        return res;
    }
};