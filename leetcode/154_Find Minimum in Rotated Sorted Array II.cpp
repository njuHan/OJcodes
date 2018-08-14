class Solution {
public:
    int findMin(vector<int>& nums) {
        int x = 0, y = nums.size()-1;
        while(x<y)
        {
            int mid = x + (y-x)/2;
            if (nums[mid]>nums[y]) x = mid+1;
            else if (nums[mid]<nums[y]) y = mid;
            else y--;
        }
        return nums[x];
    }
};