#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
#include<numeric>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct Node
{
	int x, y, height;
	Node(int x, int y, int h) :x(x), y(y), height(h) {}
	bool operator < (const Node& rhs) const
	{
		return this->height > rhs.height;
	}
};


class Solution {
public:
	int cutOffTree(vector<vector<int>>& forest) {
		if (forest.empty()) return 0;
		m = forest.size(); n = forest[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (forest[i][j] != 0) que.emplace(Node(i, j, forest[i][j]));

		pair<int, int> pos = make_pair(0, 0);
		int ans = 0;
		while (!que.empty())
		{
			Node temp = que.top(); que.pop();
			int dist = getdist(pos, temp.x, temp.y, forest);
			//cout<<pos.first<<", "<<pos.second<<endl;
			//cout<<temp.x<<", "<<temp.y<<", "<<dist<<endl;
			if (dist == -1) return -1;
			ans += dist;
			pos.first = temp.x;
			pos.second = temp.y;
		}
		return ans;

	}
private:
	priority_queue<Node> que;
	vector<vector<bool>> vis;
	int m, n;

	/*
	If you set the visited to true after a node is polled from the queue, 
	you will get TLE. 
	However, if you set visited to true immediately after it is add into the queue, 
	you will be fine,
	*/
	int getdist(pair<int, int> src, int x2, int y2, vector<vector<int>>& forest)
	{
		vis = vector<vector<bool>>(m, vector<bool>(n, 0));
		queue<pair<int, int>> que;
		que.push(src);
		vis[src.first][src.second] = 1;
		int dist = 0;
		while (!que.empty())
		{
			int sz = que.size();
			while (sz--)
			{
				pair<int, int> temp = que.front(); que.pop();
				if (temp.first == x2 && temp.second == y2) return dist;
				for (int i = 0; i < 4; i++)
				{
					int x = temp.first + dx[i], y = temp.second + dy[i];
					if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || forest[x][y] == 0) continue;
					que.push(make_pair(x, y));
					vis[x][y] = 1;
				}
			}
			dist++;
		}
		return -1;
	}
};