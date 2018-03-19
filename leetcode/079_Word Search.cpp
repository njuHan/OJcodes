#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0 || word.size() == 0) return false;
		int m = board.size(), n = board[0].size();
		this->b = board;
		this->w = word;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{	
				if (word[0] == board[i][j])
				{
					
					if (search(i, j, 0))
						return true;
					this->b = board;
					this->w = word;
				}
					
			}
					
		}
		return false;
	}
private:
	//使用成员变量提速
	vector<vector<char>> b;
	string w;
	bool search(int i, int j, int cur)
	{
		if (cur == w.size()) return true;
		if (i < 0 || j < 0 || i == b.size() || j == b[0].size() || b[i][j]!=w[cur]) return false;
		char temp = b[i][j];
		b[i][j] = '\0';
		bool ans =  (search(i - 1, j, cur + 1) || search(i + 1, j, cur + 1) || search(i, j - 1, cur + 1) || search(i, j + 1, cur + 1));
		b[i][j] = temp;
		return ans;

	}
};

int main()
{
	Solution solu;
	vector<vector<char>> board = { {'a','a'} };
	string word = "aaa";
	bool ans = solu.exist(board, word);
	system("pause");
	return 0;
}