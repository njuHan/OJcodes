#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		this->num = n;
		if (num <= 0)
			return ans;
		this->vis = vector<vector<bool>>(3, vector<bool>(2*num, false));
		vector<int> vec;
		searchQ(0, vec);
		for (int i = 0; i < ansIdx.size(); i++)
		{
			vector<string> ansi;
			for (int j = 0; j < ansIdx[i].size(); j++)
			{
				string temp(num, '.');
				temp[ansIdx[i][j]] = 'Q';
				ansi.push_back(temp);
			}
			ans.push_back(ansi);
		}
		return ans;
	}
	//讨论 curCol列的皇后，
	void searchQ(int curCol, vector<int>& vec)
	{
		if (curCol == num)
		{
			ansIdx.push_back(vec);
			return;
		}
		for (int i = 0; i < num; i++)
		{
			if (!vis[0][i] && !vis[1][curCol + i] && !vis[2][curCol - i + num])
			{
				vis[0][i] = vis[1][curCol + i] = vis[2][curCol - i + num] = true;
				vec.push_back(i);
				searchQ(curCol + 1, vec);

				//go back
				vec.pop_back();
				vis[0][i] = vis[1][curCol + i] = vis[2][curCol - i + num] = false;
			}
		}
	}
private:
	vector<vector<string>> ans;
	vector<vector<int>> ansIdx;
	int num;
	vector<vector<bool>> vis;
};
int main()
{
	Solution solu;
	vector<vector<string>> ans = solu.solveNQueens(8);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << endl;
		cout << "------------" << endl;
	}
	cout << "ans num: " << ans.size() << endl;
	system("pause");
	return 0;
}