class Solution {
public:
    int countRotations(string s, int k) {
        int n =s.size();
        vector<int>scores;

        string temp=s;

        for(int j=0;j<n;j++){
            int cnt=0;
            for(int i=0;i<n-1;i++){
                if(temp[i]==temp[i+1])
                    cnt++;
            }
            scores.push_back(cnt);

            char y=temp[0];
            int z=0;
            for(int k=1;k<n;k++)
                temp[z++]=temp[k];

            temp[n-1]=y;
        }

        int cnt=0;
        for(int i=0;i<scores.size();i++){
            if(scores[i]==k)
                cnt++;
        }

        return cnt;
    }
};