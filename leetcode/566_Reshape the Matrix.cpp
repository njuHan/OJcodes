class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        int m = nums.size(), n = nums[0].size();
        if (m*n!=r*c) return nums;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int k = i*n + j;
                ans[k/c][k%c] = nums[i][j];
            }
        return ans;
    }
};