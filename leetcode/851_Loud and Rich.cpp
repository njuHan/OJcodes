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
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		ans = vector<int>(n, -1);
		graph = vector<vector<bool>>(n, vector<bool>(n, 0));
		for (auto& e : richer)
			graph[e[1]][e[0]] = 1;
		for (int i = 0; i<n; i++) dfs(i, quiet);
		return ans;
	}
private:
	vector<vector<bool>> graph;
	vector<int> ans;
	int dfs(int x, vector<int>& quiet)
	{
		if (ans[x] != -1) return ans[x];
		ans[x] = x;
		for (int j = 0; j < quiet.size(); j++)
			if (graph[x][j])
			{
				int temp = dfs(j, quiet);
				ans[x] = quiet[ans[x]]> quiet[temp] ? temp : ans[x];
			}
		return ans[x];
	}
};