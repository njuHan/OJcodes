#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) 
	{
		int len = A.size();
		if (len < 3) return 0;
		vector<int> dp(len, 0); //dp[i]:以i结尾的符合条件的串的个数
		dp[2] = (A[0] - A[1] == A[1] - A[2]);
		int sum = dp[2];
		for (int i = 3; i < len; i++)
		{
			if (A[i - 2] - A[i - 1] == A[i - 1] - A[i])
			{
				dp[i] = dp[i - 1] + 1;
				sum += dp[i];
			}
			
		}
		return sum;
	}
};

int main()
{
	Solution solu;
	vector<int> A = { 1,2,3,4,5 };
	int ans = solu.numberOfArithmeticSlices(A);
	printf("%d", ans);
	system("pause");
	return 0;
}