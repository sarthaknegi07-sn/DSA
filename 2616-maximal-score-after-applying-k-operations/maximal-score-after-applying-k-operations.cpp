class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(auto it:nums)
            pq.push(it);

        long long score =0;
        while(k--){
            int x=pq.top();
            pq.pop();
            score+=x;
            pq.push(ceil((x+2)/3));
        }
        return score;
    }
};