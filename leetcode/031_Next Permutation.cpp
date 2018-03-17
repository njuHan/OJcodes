#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation2(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
		for (auto e : nums) cout << e;
	}
	void nextPermutation(vector<int>& nums) 
	{
		int len = nums.size();
		if (len < 1) return;
		int i;
		for (i = len - 1; i - 1 >= 0; i--)
		{
			if (nums[i - 1] < nums[i])
				break;
		}
		if (i == 0)
			reverse(nums.begin(), nums.end());
		else
		{
			//find first nums[q] > nums[p]
			int p = i - 1, q = len - 1;
			while (nums[q] <= nums[p]) q--;
			int temp = nums[p];
			nums[p] = nums[q];
			nums[q] = temp;
			int j = len - 1;
			while (i < j)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++;
				j--;
			}
		}
		//for (auto e : nums) 这题不需要输出
		//	printf("%d", e);
	}
};

int main()
{
	Solution solu;
	vector<int > vec = { 3,1,2 };
	solu.nextPermutation(vec);

	system("pause");
	return 0;
}