#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution2 {
public:
	int totalNQueens(int n) {
		vis = vector<vector<bool>>(3, vector<bool>(2 * n, 0));
		search(0, n);
		return ans;
	}
private:
	int ans;
	vector<vector<bool>> vis; // 记录 列、正反对角线 
	void search(int row, int n)
	{
		if (row == n) { ans++; return; }
		for (int j = 0; j < n; j++)
		{
			if (!vis[0][j] && !vis[1][row + j] && !vis[2][row - j + n])
			{
				vis[0][j] = vis[1][row + j] = vis[2][row - j + n] = 1;
				search(row + 1, n);
				vis[0][j] = vis[1][row + j] = vis[2][row - j + n] = 0;
			}
		}
	}
};

class Solution {
public:
	int totalNQueens(int n) 
	{
		if (n <= 0) return 0;
		this->cnt = 0;
		this->vis = vector<vector<bool>>(3, vector<bool>(2 * n, false));
		this->addCnt(0, n);
		return cnt;
	}
	void addCnt(int cur, int n)
	{
		if (cur == n)
		{
			cnt++;
			return;
		}
		for (int j = 0; j < n; j++)
		{
			if (!vis[0][j] && !vis[1][cur + j] && !vis[2][cur - j + n])
			{
				vis[0][j] = vis[1][cur + j] = vis[2][cur - j + n] = true;
				addCnt(cur + 1, n);
				vis[0][j] = vis[1][cur + j] = vis[2][cur - j + n] = false;
			}
		}
		
	}
private:
	vector<vector<bool>> vis;
	int cnt;
};

int main()
{
	Solution solu;
	
	int ans = solu.totalNQueens(8);
	cout << ans;
	system("pause");
	return 0;
}