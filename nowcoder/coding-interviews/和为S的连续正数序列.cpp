
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum < 2) return ans; //at least 2 numbers
		int lo = 1, hi = 2, mid = sum / 2, cur = 3;
		while (lo<=mid)
		{
            if (cur == sum) pushAns(lo, hi);
			cur += ++hi;
			while (lo<=mid && cur>sum)
				cur -= lo++;
		}
		return ans;
	}
private:
	vector<vector<int>> ans;
	void pushAns(int lo, int hi)
	{
		vector<int> vec;
		for (int i = lo; i <= hi; i++) vec.emplace_back(i);
		ans.emplace_back(vec);
	}
};