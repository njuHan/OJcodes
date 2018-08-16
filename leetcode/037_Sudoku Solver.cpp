#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution2 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cell, 0, sizeof(cell));
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
            {
                if (board[i][j]!='.')
                {
                    int num = board[i][j] - '0', k = i/3*3 + j/3;
                    row[i][num] = col[j][num] = cell[k][num] = 1;
                }
            }
        solve(0,0,board);
    }
private:
    bool row[9][10] , col[9][10], cell[9][10];
    bool solve(int x, int y, vector<vector<char>>& board)
    {
        if (x==9) return true;
        if (y==9) return solve(x+1,0,board);
        if (board[x][y]!='.') return solve(x,y+1, board);
        int k = x/3*3 + y/3;
        for (int num = 1; num<=9; num++)
        {
            if (!row[x][num] && !col[y][num] && !cell[k][num])
            {
                row[x][num] = col[y][num] = cell[k][num] = 1;
                board[x][y] = num + '0';
                if (solve(x,y+1,board)) return true;
                row[x][num] = col[y][num] = cell[k][num] = 0;
                board[x][y] = '.';
            }
        }
        return false;
    }
   
};


/*
static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
*/
static vector<vector<char>> board = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return vector<vector<char>>{};
}();


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		load(board);
		solve(board, 0, 0);
	}
private:
	bool row[9][9], col[9][9], cell[9][9];
	void load(vector<vector<char>>& board)
	{
		for (int i=0; i<9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1;
					row[i][num] = col[j][num] = cell[i / 3 * 3 + j / 3][num] = 1;
				}
			}
	}
	bool solve(vector<vector<char>>& board, int i, int j)
	{
		if (i == 9) return true;
		if (j == 9) return solve(board, i + 1, 0);
		if (board[i][j] != '.') return solve(board, i, j + 1);
		for (int num = 0; num < 9; num++)
		{
			int k = i / 3 * 3 + j / 3;
			if (!row[i][num] && !col[j][num] && !cell[k][num])
			{
				board[i][j] = num + 1 + '0';
				row[i][num] = col[j][num] = cell[k][num] = 1;
				if (solve(board, i, j + 1)) return true;
				board[i][j] = '.';
				row[i][num] = col[j][num] = cell[k][num] = 0;
			}
		}
		return false;
	}
};