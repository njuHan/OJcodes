class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while (lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == nums[mid^1]) lo = mid+1;
            else hi = mid;
        }
        return nums[hi];
    }
};