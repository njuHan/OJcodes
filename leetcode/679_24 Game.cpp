#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
#include<numeric>
using namespace std;


class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<double> temp(nums.begin(), nums.end());
		do
		{
			if (valid(temp)) return true;
		} while (next_permutation(temp.begin(), temp.end()));
		return false;
	}
private:
	const double error = 1e-5;
	bool valid(vector<double> nums)
	{
		int len = nums.size();
		if (len == 1) return abs(nums[0] - 24.0) < error;
		for (int i = 0; i < len - 1; i++)
		{
			for (auto next : nexts(nums, i))
				if (valid(next)) return true;
		}
		return false;
	}
	vector<vector<double>> nexts(vector<double>& nums, int i)
	{
		vector<double> results = { nums[i] + nums[i + 1], nums[i] - nums[i + 1] ,nums[i] * nums[i + 1] };
		if (nums[i - 1] != 0) results.push_back(nums[i] / nums[i + 1]);
		vector<vector<double>> ans;
		for (double r : results)
		{
			vector<double> next;
			for (int j = 0; j < (int)nums.size(); j++)
			{
				if (j == i) next.push_back(r);
				else if (j == i + 1) continue;
				else next.push_back(nums[j]);
			}
			ans.emplace_back(next);
		}
		return ans;
	}
};