class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i=0; i<profit.size(); i++) jobs.emplace_back(difficulty[i], profit[i]);
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int j = 0, n = jobs.size(), prf = 0, ans = 0;
        for (int i=0; i<worker.size(); i++)
        {
            while( j<n && jobs[j].first <= worker[i]) {prf = max(jobs[j].second, prf); j++; }
            ans += prf;
        }
        return ans;
    }
};