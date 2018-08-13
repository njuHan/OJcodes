class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = sqrt(c);
        while(i<=j)
        {
            int sum = i*i + j*j;
            if (c == sum ) return 1;
            else if (c < sum) j--;
            else i++;
        }
        return 0;
    }
};