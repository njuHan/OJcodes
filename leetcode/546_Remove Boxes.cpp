#include<iostream>
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

// https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions

int dp[100][100][100];
class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		memset(dp, 0, sizeof(dp));
		this->boxs = boxes;
		this->n = boxes.size();
		return removeSub(0, n - 1, 0);
	}
private	:
	int n;
	vector<int> boxs;
	int removeSub(int i, int j, int k)
	{
		if (i > j) return 0;
		if (dp[i][j][k] > 0) return dp[i][j][k];
		for (; i + 1 <= j && boxs[i] == boxs[i + 1]; i++, k++);
		int ans = (k + 1)*(k + 1) + removeSub(i + 1, j, 0);
		for (int m = i + 1; m <= j; m++)
		{
			if (boxs[m] == boxs[i])
				ans = max(ans, removeSub(m, j, k + 1) + removeSub(i + 1, m - 1, 0));
		}
		return dp[i][j][k] = ans;
	}
};