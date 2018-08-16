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
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0}, col[9][10] = {0}, cell[9][10] = {0};
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                if (board[i][j]!='.')
                {
                    int num = board[i][j]-'0', k = i/3*3 + j/3;
                    if (row[i][num] || col[j][num] || cell[k][num])
                        return false;
                    row[i][num] = col[j][num] = cell[k][num] = 1;
                }
        return true;
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
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> row[9], col[9], cell[9];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					char ch = board[i][j];
					int k = i / 3 * 3 + j / 3;
					if (row[i].count(ch) || col[j].count(ch) || cell[k].count(ch))
						return false;
					else
					{
						row[i].insert(ch);
						col[j].insert(ch);
						cell[k].insert(ch);
					}
				}
			}
		}
		return true;
	}

	bool isValidSudoku2(vector<vector<char>>& board) {
		bool row[9][9] = { 0 }, col[9][9] = { 0 }, cell[9][9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1;
					int k = i / 3 * 3 + j / 3;
					if (row[i][num] || col[j][num] || cell[k][num])
						return false;
					else
						row[i][num] = col[j][num] = cell[k][num] = 1;
				}
			}
		}
		return true;
	}

};