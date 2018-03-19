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
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		//dp[i]:  the number of unique BST for a sequence of length i
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 0; j < i; j++) // j: the number of left nodes
				dp[i] += dp[j]*dp[i - j - 1];
		return dp[n];
	}
};

int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}