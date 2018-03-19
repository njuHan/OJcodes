#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int len = matrix.size();
		if (len <= 1) return;
		for (int i = 0; i <= len / 2; i++)
		{
			for (int j = i; j < len - i -1; j++)
			{
				int newval = matrix[i][j];
				int nexti = j, nextj = len - 1 - i;
				// Ñ­»·×ªÈ¦È¦Öð¸öÌæ»»
				while (!(nexti == i && nextj == j))
				{
					int temp = matrix[nexti][nextj];
					matrix[nexti][nextj] = newval;
					newval = temp;
					int tempi = nexti;
					nexti = nextj, nextj = len - 1 - tempi;
				}
				matrix[i][j] = newval;
			}
		}
	}
	
};
int main()
{
	Solution solu;
	
	vector<vector<int>> ans = { {1,2,3,3},{4,5,6,6},{7,8,9,9},{10,11,12,12} };
	solu.rotate(ans);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d, ", ans[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}