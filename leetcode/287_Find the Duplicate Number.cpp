#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow, fast;
		slow = fast = 0;
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return fast;
	}
};

int main()
{

	system("pause");
	return 0;
}



