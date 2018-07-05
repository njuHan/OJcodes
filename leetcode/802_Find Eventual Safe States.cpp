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

//topo sort
class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vis = vector<int>(graph.size(), 0);
		vector<int> ans;
		for (int u = 0; u < graph.size(); u++)
		{
			if (vis[u] == 0) topoDFS(u, graph);
			if (vis[u] == 1) ans.emplace_back(u);
		}
		return ans;
	}
private:
	vector<int> vis;
	bool topoDFS(int u, vector<vector<int>>& graph)
	{
		vis[u] = -1;
		for (int v : graph[u])
		{
			if (vis[v] == -1) return false;
			if (vis[v] == 0 && topoDFS(v, graph) == false) return false;
		}
		vis[u] = 1;
		return true;
	}
};

//out degree, queue
class Solution2 {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<int> outdgree(graph.size(), 0);
		queue<int> que;
		vector<int> ans;
		vector<vector<int>> Rgraph(graph.size());
		for (int u = 0; u < graph.size(); u++)
		{
			if ((outdgree[u] = graph[u].size()) == 0)
				que.push(u);
			for (int v : graph[u]) Rgraph[v].push_back(u);
		}
		while (!que.empty())
		{
			int v = que.front(); que.pop();
			ans.emplace_back(v);
			for (int u : Rgraph[v])
				if (--outdgree[u] == 0) que.push(u);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};