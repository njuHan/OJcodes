class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //return 1;
        int n = piles.size();
        vector<int> dp(n, 1);
        for (int d = 1; d < n; d++)
            for (int i=0; i + d < n; i++)
                dp[i] = max(piles[i] - dp[i+1], piles[i+d] - dp[i]);
        return dp[0]>0;
    }
};