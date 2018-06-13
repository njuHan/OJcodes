class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() <= 1) return 0;
		ans = 0;
		nums = data;
		mergeSort(0, data.size());
		return ans;
	}
private:
	vector<int> nums;
	int ans;
	//[x, y)
	void mergeSort(int x, int y)
	{
		if (y - x <= 1) return;
		int mid = x + (y - x) / 2;
		mergeSort(x, mid);
		mergeSort(mid, y);
		merge(x, mid, y);
	}
	void merge(int x, int mid, int y)
	{
		vector<int> temp(y-x);
		int i = x, j = mid, k=0;
		while (i<mid || j<y)
		{
			if (j == y || (i < mid && nums[i] <= nums[j]))
			{
				temp[k++] = nums[i++];
				ans += j - mid;
                ans %= 1000000007;
			}
			else
				temp[k++] = nums[j++];
		}
		for (int i = 0; i < y - x; i++) nums[i + x] = temp[i];
	}
};
