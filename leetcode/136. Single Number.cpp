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
	int longestConsecutive(vector<int>& nums) {
		int ans = 0;
		for (auto e : nums)
			ans ^= e;
		return ans;
	}
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}