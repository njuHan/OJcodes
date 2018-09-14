class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n<=1 || bits[n-2]==0) return 1;
        vector<bool> dp(n+1, 0); dp[0] = 1;
        for (int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1]&&bits[i-1] == 0 || i>=2&& dp[i-2] && bits[i-2]==1;
        }
        return !dp[n-2];
    }
};