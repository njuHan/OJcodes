// 最长公共子序列
int lenLCS(string a, string b)
{
	int m = a.length(), n = b.length();
	// dp[i][j] 表示 a 的前 i个字符与 b 的前 j 个字符最长公共子序列的长度
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for (int i=1; i<=m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	return dp[m][n];
}
int main()
{
	string a = "123456789", b = "013579";
	cout << lenLCS(a, b);
	system("pause");
	return 0;
}