#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
using namespace std;

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		for (int u = 0; u < graph.size(); u++)
		{
			if (!nodeSet[0].count(u) && !nodeSet[1].count(u))
				if (dfs(u, 0, graph) == 0) return 0;
		}
		return 1;
	}
private:
	unordered_set<int> nodeSet[2];
	bool dfs(int u, int idx, vector<vector<int>>& graph)
	{
		nodeSet[idx].insert(u);
		for (int v : graph[u])
		{
			if (nodeSet[idx].count(v)) return false;
			if (nodeSet[!idx].count(v)) continue;
			if (dfs(v, !idx, graph) == false) return false;
		}
		return true;
	}
};

//BFS
class Solution2 {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		unordered_set<int> nodeSet[2];
		vector<bool> vis(graph.size(), 0);
		queue<int> que;
		for (int u = 0; u < graph.size(); u++)
		{
			if (vis[u]) continue;
			int idx = 0;
			vis[u] = 1;
			que.push(u);
			nodeSet[idx].insert(u);
			while (!que.empty())
			{
				int m = que.size();
				while (m--)
				{
					int u = que.front(); que.pop();
					for (int v : graph[u])
					{
						if (nodeSet[idx].count(v)) return false;
						if (!vis[v])
						{
							vis[v] = 1;
							que.push(v);
							nodeSet[!idx].insert(v);
						}
					}
				}
				idx = !idx;
			}
		}
		return 1;
	}
	
};