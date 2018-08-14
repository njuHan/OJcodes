#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		m = board.size(); n = board[0].size();
		vis = vector<vector<int>>(m, vector<int>(n, -1));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O'&& vis[i][j] == -1)
				{
					if (!dfs(i, j, -1, board))
					{
						//cout << i << "," << j << endl;
						dfs(i, j, 0, board);
					}

				}
			}
	}
private:
	vector<vector<int>> vis; //-1: unvisited ， 0: visited ， 1: filled
	vector<vector<char>> board;
	int m, n;
	bool dfs(int i, int j, int op, vector<vector<char>>& board)
	{
		if (i < 0 || j < 0 || i >= m || j >= n) return true;
		if (board[i][j] == 'O' && vis[i][j] == op)
		{
			vis[i][j]++;
			if (op == 0) board[i][j] = 'X';
			bool up = dfs(i - 1, j, op, board), down = dfs(i + 1, j, op, board), left = dfs(i, j - 1, op, board), right = dfs(i, j + 1, op, board);
			return up || down || left || right;
		}
		return false;
	}
};

int dx[] = { 1, -1, 0,0 };
int dy[] = { 0,0,1, - 1 };
class Solution2 {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		m = board.size(), n = board[0].size();
		for (int i = 0; i < m; i++)
			dfs(i, 0, board), dfs(i, n - 1, board);
		for (int j = 0; j < n; j++)
			dfs(0, j, board), dfs(m - 1, j, board);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == 'a') board[i][j] = 'O';
			}
	}
private:
	int m, n;
	void dfs(int x, int y, vector<vector<char>>& board) 
	{
		if (x < 0 || x >= m || y < 0 || y >= n || board[x][y]!='O') return; 
		board[x][y] = 'a'; //把连通边界的O 标记为 a
		for (int i = 0; i < 4; i++)
			dfs(x + dx[i], y + dy[i], board);
	}
};