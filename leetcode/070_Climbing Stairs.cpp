class Solution {
public:
    int climbStairs(int n) {
        if (n<2) return 1;
        int f1 = 1, f2 = 1, ans;
        for (int i=2; i<=n; i++)
        {
            ans = f1 + f2;
            f1 = f2;
            f2 = ans;
        }
        return ans;
    }
};