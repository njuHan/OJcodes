#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	//ÀºœÎ¿‡À∆BFS
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) return 0;
		int curLevel = nums[0], nextLevel = nums[0] + 0;
		int step = 0, i = 0;
		while (i<len)
		{
			while (i <= curLevel)
			{
				nextLevel = max(nextLevel, i + nums[i]);
				nextLevel = min(len, nextLevel);
				i++;
			}
			curLevel = nextLevel;
			step++;
		}
		return step;
	}
};

int main()
{
	vector<int> v = { 2,3,1,1,4 };
	Solution solu;
	int  ans = solu.jump(v);
	cout << ans;
	system("pause");
	return 0;
}