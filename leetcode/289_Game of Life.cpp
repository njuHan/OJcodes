#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;
		int m = board.size(), n = board[0].size();
		for (int i=0; i<m; i++)
			for (int j = 0; j < n; j++)
			{
				int cnt = 0;
				for (int di = max(0, i-1); di<=min(m-1, i+1); di++)
					for (int dj = max(0, j - 1); dj <= min(n - 1, j + 1); dj++)
					{
						if (board[di][dj]&1) cnt++;
					}
				if (cnt == 3 || cnt - board[i][j] == 3) board[i][j] = board[i][j] | 2;
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				board[i][j] >>= 1;
	}
};