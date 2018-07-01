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
#include<ctime>
using namespace std;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { -1,-2,-2,-1,1,2,2,1 };

// dfs TLE error
class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		if (K <= 0) return 1.0;
		cnt = 0;
		n = N;
		dfs(r, c, K);
		return (double)cnt / pow(8.0, K);
	}
private:
	int cnt;
	int n;
	void dfs(int x, int y, int step)
	{
		if (x < 0 || x >= n || y < 0 || y >= n ) return;
		if (step == 0) { cnt++; return; }
		for (int i = 0; i < 8; i++)
		{
			dfs(x + dx[i], y + dy[i], step - 1);
		}
	}
};

class Solution2 {
public:
	double knightProbability(int N, int K, int r, int c) {
		n = N;
		n2 = (N + 1) / 2;  //正方形对称性，取四分之一面积(奇数边多1行列)
		vector<vector<double>>	dp(K + 1, vector<double>(n2*n2, -1.0));
		return search(r, c, K, dp);
	}
private:
	int n;
	int n2;
	double search(int x, int y, int step, vector<vector<double>>& dp)
	{
		if (step == 0) return 1.0;
		if (x > (n - 1) / 2) x = n - 1 - x;
		if (y > (n - 1) / 2) y = n - 1 - y;
		int key = x*n2 + y;
		if (dp[step][key] != -1.0) return dp[step][key];
		dp[step][key] = 0; // initial
		for (int i = 0; i < 8; i++)
		{
			int nextx = x + dx[i], nexty = y + dy[i];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) continue;
			dp[step][key] += 0.125 * search(x + dx[i], y + dy[i], step - 1, dp);
		}
		return dp[step][key];
	}
	
};