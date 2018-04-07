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


//solution ： https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C++-O(n)-solution-two-pass
class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> cnt, end;
		for (int& e : nums) cnt[e]++;
		for (int& e : nums)
		{
			if (cnt[e] == 0) continue;
			cnt[e]--;
			if (end[e - 1] > 0) //把e添加到e-1结尾的子序列后
			{
				end[e - 1]--;
				end[e]++;
			}
			else if (cnt[e + 1] && cnt[e + 2]) //新建e开头的子序列
			{
				end[e + 2]++;
				cnt[e + 1]--;
				cnt[e + 2]--;
			}
			else return false;
		}
		return true;
	}
};

int main()
{

	vector<int>  vec = { 1,2,3,3,4,5 };
	Solution solu;
	bool ans = solu.isPossible(vec);

	system("pause");
	return 0;
}



