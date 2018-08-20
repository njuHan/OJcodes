class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 三个最大的正数 或者 最大的正数和最小的两个负数
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = INT_MIN; min1 = min2 = INT_MAX;
        for (int& num : nums)
        {
            if (num > max1) {max3 = max2; max2 = max1; max1 = num;}
            else if (num > max2) {max3 = max2; max2 = num;}
            else if (num > max3) max3 = num;
            
            if (num < min1) { min2 = min1; min1 = num;}
            else if (num < min2) min2 = num;
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};