// 1 pass
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        int c = 0;
        for (int i=1; i<=nums.size(); i++)
        {
            int val = abs(nums[i-1]);
            c ^= i^val;
            if (nums[val-1]<0) ans[0] = val;
            else nums[val-1] = -nums[val-1];
        }
        ans[1] = c^ans[0];
        return ans;
    }
};
// 2 passes
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        for (int num : nums)
        {
            num = abs(num);
            if (nums[num-1]<0) ans[0] = num;
            else nums[num-1] = -nums[num-1];
        }
        for (int i=0; i<nums.size() ;i++)
            if (nums[i] > 0) ans[1] = i+1;
        return ans;
    }
};