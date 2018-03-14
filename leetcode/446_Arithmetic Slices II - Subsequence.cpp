#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std; 
class Solution {
public:
	// 首先思路就是用二维dp数组刷表，dp[i][j]，表示以i结尾且元素差为j的串的个数
	// 因为元素差可能很大，有正有负，j的维度不好搞
	// 看了solution，用的vector<map>, 厉害了
	// 还要注意 INT_MIN - INT_MAX 会int溢出的情况，这时就需要用long long delt
	//考虑了两个元素的串 https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solution/
	int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size();
		if (len < 3) return 0;
		vector<map<long long, int>> dp(len);
		int ans = 0;
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				long long delt = (long long)A[j] - (long long)A[i];
				int sum = 0;
				if (dp[j].count(delt) != 0)
				{
					sum = dp[j][delt];
				}
				ans += sum; //以i结尾，至少3个元素子串个数
				dp[i][delt] += sum + 1; //以i结尾，至少2个元素子串个数
				//2个到3个，只需去掉A[i-1]A[i]这一个元素
			}
		}
		return ans;
	}
};
int main()
{
	Solution solu;
	vector<int> A = { 2, 4, 6, 8, 10 };
	int ans = solu.numberOfArithmeticSlices(A);
	printf("%d", ans);
	system("pause");
	return 0;
}