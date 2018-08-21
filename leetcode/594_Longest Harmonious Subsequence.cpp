class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int& num : nums) cnt[num]++;
        for (auto& e : cnt) 
        {
            if (cnt.count(e.first+1))
                ans = max(ans, e.second + cnt[e.first+1]);
        }
        return ans;
    }
};