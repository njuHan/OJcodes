#include<iostream>
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


class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		m = board.size(); n = board[0].size();
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}
		dfs(click[0], click[1], board);
		return board;
	}
private:
	int m, n;
	//注意这是8连通
	void dfs(int x, int y, vector<vector<char>>& board)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E') return;
		int num = check(x, y, board);
		if (num == 0)
		{
			board[x][y] = 'B';
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					if (i == 0 && j == 0) continue;
					int nx = x + i, ny = y + j;
					dfs(nx, ny, board);
				}
		}
		else board[x][y] = num + '0';

	}
	int check(int x, int y, vector<vector<char>>& board)
	{
		int ans = 0;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0) continue;
				int nx = x + i, ny = y + j;
				ans += (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M');
			}
		return ans;
	}
};