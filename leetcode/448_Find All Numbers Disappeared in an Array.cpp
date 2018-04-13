#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			int idx = (nums[i]>0 ? nums[i]:-nums[i]) - 1;
			nums[idx] = nums[idx]>0 ? -nums[idx] : nums[idx];
		}
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				ans.push_back(i + 1);
		}
		return ans;
	}
};

int main()
{

	return 0;
}