class Solution {
public:
    int minMoves(vector<int>& nums) {
        //https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
        if (nums.empty()) return 0;
        int min = nums[0], sum = 0;
        for (int num : nums)
        {
            sum += num;
            if (num < min) min = num;
        }
        return sum - nums.size()*min;
    }
};