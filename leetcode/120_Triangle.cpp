#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int minimumTotal2(vector<vector<int>>& triangle) {
		int len = triangle.size();
		if (len < 1) return 0;
		vector<vector<int>> dp(len, vector<int>(len, INT_MAX));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
		int ans = dp[len - 1][0];
		for (int i = 1; i < len; i++)
			ans = min(ans, dp[len - 1][i]);
		return ans;
	}
	//O(n) space, from bottom to top
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		if (len < 1) return 0;
		//last line
		vector<int> dp = triangle[len - 1];
		for (int row = len - 2; row >= 0; row--)
		{
			for (int j = 0; j < triangle[row].size(); j++)
			{
				dp[j] = min(dp[j], dp[j + 1]) + triangle[row][j];
			}
		}
		return dp[0];
	}
};

int main()
{


	system("pause");
	return 0;
}