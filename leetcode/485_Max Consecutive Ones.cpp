class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (int& num : nums) ans = max(ans, cnt = num==1 ? cnt+1 : 0);
        return ans;
    }
};