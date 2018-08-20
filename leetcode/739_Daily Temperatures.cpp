class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++)
        {
            while (!sk.empty() && temperatures[sk.top()]<temperatures[i])
            {
                ans[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return ans;
    }
};