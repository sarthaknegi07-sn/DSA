class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> pref(n);
        pref[0] = tasks[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + tasks[i];

        long long work = 0;
        vector<int> ans;

        for (int shift : shifts) {
            work += shift;

            if (work >= pref[n - 1]) {
                ans.push_back(0);   // all tasks completed
                work = 0;           // restart for next shift
            } else {
                int completed = upper_bound(pref.begin(), pref.end(), work) - pref.begin();
                ans.push_back(n - completed);
            }
        }

        return ans;
    }
};