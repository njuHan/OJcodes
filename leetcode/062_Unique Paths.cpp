#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution3 {
public:
    int uniquePaths(int m, int n) {
        //排列组合， 总步数 m-1+n-1, 向下 m-1, 求C(m-1+n-1, m-1)
        int s = m + n -2;
        m = min(m,n)-1;
        long long ans = 1; // C(n,0)
        for (long i=1; i<=m; i++)
            ans = ans * (s-i+1)/(long long)i;
     
        return ans;
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i=0; i<m; i++)
            for (int j=1; j<n; j++)
                dp[j] = dp[j-1] + dp[j];
        return dp[n-1];
    }
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int& ans = dp[i][j];
				if (i > 0)
					ans += dp[i - 1][j];
				if (j > 0)
					ans += dp[i][j - 1];	
			}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	Solution solu;
	int ans = solu.uniquePaths(2,2);
	printf("%d\n", ans);
	system("pause");
	return 0;
}