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
using namespace std;

class Solution2 {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = dp[2] = 1; 
        for (int i = 2; i<=n; i++)
        {
            for (int j=2; j<i && j<=4; j++)
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
        }
        return dp[n];
    }
};

// https://leetcode.com/problems/integer-break/discuss/80721/Why-factor-2-or-3-The-math-behind-this-problem.

class Solution {
public:
	int integerBreak(int n) {
		less10 = { 0,0, 1,2,4,6,9,12,18,27 };
		return f(n);
	}
private:
	vector<int> less10;
	int f(int n)
	{
		if (n < 10) return less10[n];
		return f(n - 3) * 3;
	}
};