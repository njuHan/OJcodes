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
#include<functional>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows < 1 || cols < 1) return 0;
		ans = 0;
		m = rows;
		n = cols;
		vis = vector<vector<bool>>(m, vector<bool>(n, 0));
		dfs(0, 0, threshold);
		return ans;
	}
private:
	int ans, m, n;
	vector<vector<bool>> vis;
	int sumNum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
	void dfs(int i, int j, int k)
	{
		if (i<0 || i>=m || j<0 || j>=n || vis[i][j] || sumNum(i) + sumNum(j) > k) return;
		ans++;
		vis[i][j] = 1;
		for (int p = 0; p < 4; p++) //×¢Òâ±äÁ¿i¸²¸Ç
			dfs(i + dx[p], j + dy[p], k);
	}
};