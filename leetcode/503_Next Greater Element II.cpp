class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> sk;
        for (int i=0; i<n+n; i++)
        {
            while(!sk.empty() && nums[sk.top()] < nums[i%n])
            {
                ans[sk.top()] = nums[i%n];
                sk.pop();
            }
            sk.push(i%n);
        }
        return ans;
    }
};