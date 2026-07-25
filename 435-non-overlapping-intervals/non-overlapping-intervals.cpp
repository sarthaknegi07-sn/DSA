class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int n =intervals.size();
        int cnt=0;

        int prevend=intervals[0][1];
        int i=1;
        while(i<n){
            if(intervals[i][0]<prevend && intervals[i-1][0]<=intervals[i][0]){
                cnt++;
                prevend=min(prevend,intervals[i][1]);
            }
            else
                prevend=intervals[i][1];
            i++;
        }
        return cnt;
    }
};