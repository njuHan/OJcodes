// leetcode https://leetcode.com/problems/course-schedule-ii/description/
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		t = numCourses;
		ans = vector<int>(numCourses), vis = vector<int>(numCourses, 0);
		graph = vector<vector<int>>(numCourses);
        for (auto e : prerequisites) graph[e.second].push_back(e.first);
		for (int u = 0; u < numCourses; u++)
			if (vis[u] == 0 && dfs(u) == false) return {};
		return ans;
	}
private:
	int t;
	vector<int> ans, vis;
	vector<vector<int>> graph;
	bool dfs(int u)
	{
		vis[u] = -1;
		for (int v : graph[u])
		{
			if (vis[v] == -1) return false;
			else if (vis[v] == 0 && dfs(v) == false) return false;
		}
		vis[u] = 1;
		ans[--t] = u; //反向添加
        return true;
	}
};
