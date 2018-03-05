//使用unordered_map (hash)
//时间复杂度O(n), 查map只需O(1)
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> myMap;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			int temp = target - nums[i];
			unordered_map<int, int>::iterator it = myMap.find(temp);
			if (it != myMap.end())
			{
				ans.push_back(it->second);
				ans.push_back(i);
				return ans;
			}
			myMap[nums[i]] = i;
		}
		return ans;
	}
};

int main()
{
	
	Solution solu;
	vector<int> vec = { 2, 7, 11, 15 };
	vector<int> ans = solu.twoSum(vec, 26);
	for (auto e : ans)
		cout << e<<" ";
	system("pause");
	return 0;
}