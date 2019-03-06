#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 2005;
int dp[maxn][maxn];
int v[maxn];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0][0] = 0;


	//由于只由一个人唱完肯定不是最优解。因此先在一个for循环内确定以下两种情况的初值
	//dp[i][0]：第二个人唱第一个音，第一个人唱后面所有音
	//dp[i][i - 1]：第一个人唱最近的一个音，第二个人唱前面所有音
	for (int i = 2; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + abs(v[i] - v[i - 1]);
		dp[i][i - 1] = dp[i - 1][i - 2] + abs(v[i - 1] - v[i - 2]);
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			// because i-1 < j, so j<i-1 in for
			dp[i][j] = dp[i - 1][j] + abs(v[i] - v[i - 1]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
		}
	}
	int ans = dp[n - 1][0];
	for (int i = 1; i < n - 1; i++)
		ans = min(ans, dp[n - 1][i]);
	cout << ans;
	//system("pause");
	return 0;
}