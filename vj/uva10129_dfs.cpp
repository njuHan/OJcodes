#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int wordNum = 26;
int graph[wordNum][wordNum];
int dgree[wordNum];
int n, t;


bool vis[wordNum];
bool used[wordNum];

//使用dfs判断连通性
void dfs(int u)
{
	vis[u] = 1;
	for (int v = 0; v < wordNum; v++)
	{
		if (graph[u][v] == 1 && vis[v] == 0)
			dfs(v);
	}
}


bool is_Connec()
{
	int cnt;
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	for (int u=0; u<wordNum; u++)
		if (used[u] && vis[u] == 0)
		{
			dfs(u);
			cnt++;
		}
	return cnt == 1;
}


int main() {
	cin >> t;
	while (t-->0)
	{
		cin >> n;
		string str;
		memset(graph, 0, sizeof(graph));
		memset(dgree, 0, sizeof(dgree));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int u = str[0] - 'a';
			int v = str[str.size() - 1] - 'a';
			graph[u][v] = graph[v][u] = 1;
			dgree[u]++;
			dgree[v]--;
			used[u] = used[v] = 1;
		}

		vector<int> d;
		for (int i = 0; i < wordNum; i++)
		{
			if (dgree[i] != 0)
				d.push_back(dgree[i]);
		}
		

		bool flag1 = (d.empty() || (d.size() == 2 && (d[0] == -1 || d[0] == 1)));
		if (flag1 && is_Connec())
			printf("Ordering is possible.\n");
		else 
			printf("The door cannot be opened.\n");

	}
	return 0;
}
