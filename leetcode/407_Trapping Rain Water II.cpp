#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
using namespace std;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size(), n;
		if (m == 0 || (n = heightMap[0].size()) == 0) return 0;
		int ans = 0;
		vector<bool> vis(m*n, false);
		//height ans idx (idx: m*i + j)
		pair<int, int> heitIdx; 
		//最小堆，高度小的最上面
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que; 
		//遍历最外层
		//i=0,m-1
		for (int j = 0; j < n; j++)
		{
			que.push(pair<int, int>(heightMap[0][j], j));
			que.push(pair<int, int>(heightMap[m-1][j],(m-1)*n+j ));
			vis[j] = vis[(m-1)*n + j] = 1;
		}
		//j=0,n-1
		for (int i = 1; i < m - 1; i++)
		{
			que.push(pair<int, int>(heightMap[i][0], i*n));
			que.push(pair<int, int>(heightMap[i][n-1], i*n + n-1));
			vis[i*n] = vis[i*n+n-1] = 1;
		}
		while (!que.empty())
		{
			pair<int, int> minNode = que.top(); que.pop();
			int x = minNode.second / n, y = minNode.second%n;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx*n + ny]) continue;
				ans += max(0, minNode.first - heightMap[nx][ny]);
				que.push(pair<int, int>(max(minNode.first, heightMap[nx][ny]), nx*n + ny));
				vis[nx*n + ny] = 1;
			}
		}
		return ans;
	}
};