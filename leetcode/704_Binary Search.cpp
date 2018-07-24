
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int x = 0, y = nums.size();
		while (x<y)
		{
			int mid = x + (y - x) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) x = mid + 1;
			else y = mid;
		}
		return -1;
	}
};