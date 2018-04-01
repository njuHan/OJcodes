
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

char graph[105][105];
int idx[105][105];
int m, n;

void dfs(int row, int col, int cnt)
{
	if (row < 0 || row >= m || col < 0 || col >= n) return;
	if (graph[row][col] == '*' || idx[row][col] > 0) return;
	idx[row][col] = cnt;
	for (int i=-1; i<=1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
				dfs(row + i, col + j, cnt);
		}
	
}

int main()
{
	
	while (scanf("%d%d", &m, &n)==2 && m && n)
	{
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][j] == '@' && idx[i][j] == 0)
					dfs(i, j, ++cnt);
		cout << cnt << endl;
	}
	//system("pause");
	return 0;
}
