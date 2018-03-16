#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal < 1) return true; //第一个人不需要选，已经达到要求，也算赢了
		int sum = (1 + maxChoosableInteger)*maxChoosableInteger >> 1;
		if (sum < desiredTotal) return false;
		if (sum == desiredTotal) return maxChoosableInteger % 2==1;
		vector<int> table(1 << maxChoosableInteger, 0);
		return dfs(table, 0, maxChoosableInteger, desiredTotal);
	}
	// 从bitmap状态开始选择的人，是否能够赢
	bool dfs(vector<int>& table, int bitmap, int m, int d)
	{
		if (table[bitmap] != 0) return table[bitmap]>0; //记忆
		if (d <= 0) return false; //现在已经不需要desiredTotal了，即上一个人已经win，现在开始选的人lose
		for (int i = 0; i < m; i++)
		{
			if (bitmap & 1 << i) //选了重复的位
				continue;
			if (dfs(table, bitmap | 1 << i, m, d - i-1) == false) //下一个人选的输了
			{
				table[bitmap] = 1; //当前人赢了
				return true;
			}
		}
		table[bitmap] = -1; 
		return false;
	}
};

int main()
{
	Solution solu;
	bool ans = solu.canIWin(10, 12);
	
	cout << ans << endl;
	system("pause");
	return 0;
}