class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> arr = {};
		search(1, k, n, arr);
		return ans;
	}
private:
	vector<vector<int>> ans;
	void search(int cur, int k, int n, vector<int>& arr)
	{
		if (k == 0 && n == 0) { ans.emplace_back(arr); return; }
		for (int i = cur; i <= 9 && i <= n; i++)
		{
			arr.emplace_back(i);
			search(i + 1, k - 1, n - i, arr);
			arr.pop_back();
		}
	}
};