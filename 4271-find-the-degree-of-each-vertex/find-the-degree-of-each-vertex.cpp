class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>res;
        int n=matrix.size();
        int m=matrix[0].size();;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1)
                    cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};