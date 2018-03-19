#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	void sortColors2(vector<int>& nums) {
		int high = nums.size() - 1;
		int low = 0;
		for (int i = 0; i <= high; i++)
		{
			//注意这两句的先后顺序不能变
			while (nums[i] == 2 && i < high) swap(nums[i], nums[high--]);
			while (nums[i] == 0 && low < i) swap(nums[i], nums[low++]);

		}
	}
	// 这样写更好理解
	void sortColors(vector<int>& nums)
	{
		// where the 0 to store, where the 2 to store
		int zero = 0, two = nums.size() - 1;
		int i = 0; //cur idx
		while (i <= two)
		{
			// 当且仅当nums[i] == 1，才 i++
			if (nums[i] == 0 && i > zero)
				swap(nums[i], nums[zero++]);
			else if (nums[i] == 2 && i<two)
				swap(nums[i], nums[two--]);
			else i++;

		}
	}
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}