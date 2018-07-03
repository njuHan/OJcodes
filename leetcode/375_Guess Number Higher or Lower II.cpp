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
#include<sstream>
#include<functional>
using namespace std;


class Solution {
public:
	//1到n 选择一个数i开始猜，i在[1,n]中开始猜的代价最小 min
	//选定i后，保证所有路径都可以赢，需要取代价最大的路径 max
	int getMoneyAmount(int n) {
		dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
		return search(1, n);
	}
private:
	vector<vector<int>> dp;
	//[x,y]
	int search(int x, int y)
	{
		if (x >= y) return 0;  //猜中
		int& ans = dp[x][y];
		if (ans > 0) return ans;
		ans = INT_MAX;
		for (int i = x; i <= y; i++)
		{
			ans = min(ans,i + max(search(x, i - 1), search(i + 1, y)));
		}
		return ans;
	}
};