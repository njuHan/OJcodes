
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

const int maxn = 105;
int graph[maxn][maxn];
int vis[maxn];
int sorted[maxn];
int m, n, t;

bool dfs(int u)
{
	vis[u] = -1;
	for (int v=0; v<n; v++)
		if (graph[u][v])
		{
			if (vis[v] == -1) return false; // has cycle
			if (vis[v] == 0)
				if (dfs(v) == false) return false; //has cycle
		}
	vis[u] = 1;
	sorted[--t] = u;
	return true;
}

bool topoSort()
{
	for (int u=0; u<n; u++)
		if (vis[u] == 0)
		{
			if (dfs(u) == false)
				return false;
		}
	return true;
}

int main()
{

	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		t = n;
		memset(graph, 0, sizeof(graph));
		memset(sorted, 0, sizeof(sorted));
		memset(vis, 0, sizeof(vis));
		int u, v;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			graph[u-1][v-1] = 1;
		}
		if (topoSort())
		{
			for (int i = 0; i < n - 1; i++)
				printf("%d ", sorted[i] + 1);
			printf("%d\n", sorted[n - 1] + 1);
		}
		else
			printf("No\n");

	}
	//system("pause");
	return 0;
}
