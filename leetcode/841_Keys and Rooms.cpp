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
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		remain = rooms.size();
		vis = vector<bool>(remain, 0);
		dfs(0, rooms);
		return remain == 0;
	}
private:
	vector<bool> vis;
	int remain;
	void dfs(int u, vector<vector<int>>& rooms)
	{
		for (int i = 0; i < rooms[u].size(); i++)
		{
			int v = rooms[u][i];
			if (vis[v] == 0)
			{
				vis[v] = 1;
				remain--;
				dfs(v, rooms);
			}
		}
	}
};

// bfs
class Solution2 {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int remain = rooms.size();
		vector<bool> inque(remain, 0);
		queue<int> que;
		que.push(0);
		inque[0] = 1;
		while (!que.empty())
		{
			int u = que.front(); que.pop();
			remain--;
			for (int i = 0; i < rooms[u].size(); i++)
			{
				int v = rooms[u][i];
				if (inque[v] == 0) {
					inque[v] = 1;
					que.push(v);
				}
			}
		}
		return remain == 0;
	}
};