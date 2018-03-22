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
		unordered_map<int, int> num2cons;
		int cnt = 0;
		for (auto e : nums)
		{
			if (num2cons[e] == 0)
			{
				num2cons[e] = num2cons[e-num2cons[e-1]] = num2cons[e+num2cons[e+1]] = num2cons[e - num2cons[e - 1]] + num2cons[e + num2cons[e + 1]] + 1;
				cnt = cnt < num2cons[e] ? num2cons[e] : cnt;
			}
		}
		return cnt;
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 100, 4, 200, 1, 3, 2 };
	int ans = solu.longestConsecutive(vec);
	cout << ans;
	
	system("pause");
	return 0;
}