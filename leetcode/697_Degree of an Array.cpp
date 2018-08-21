class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, first;
        int degree = 0, ans = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (first.count(nums[i])==0) first[nums[i]] = i;
            ++cnt[nums[i]];
            // 出现更大degree时，直接更新ans
            if (cnt[nums[i]] > degree)
            {
                ans = i - first[nums[i]] + 1;
                degree = cnt[nums[i]];
            }
            //出现相同degree时，直接更新ans为最小值
            else if (cnt[nums[i]]==degree)
            {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }
        return ans;
    }
};