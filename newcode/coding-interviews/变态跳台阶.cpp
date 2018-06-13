class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 1) return 1;
        int  pre = 1, ans;
        for (int i = 2; i <= number; i++)
        {
            ans = pre<<1;
            pre = ans;
        }
        return ans;
    }
};