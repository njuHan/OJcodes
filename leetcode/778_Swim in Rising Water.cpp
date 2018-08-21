int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct T
{
	int x, y, t;
	T(int _x = 0, int _y = 0, int _t = 0):x(_x), y(_y), t(_t){}
	bool operator < (const T& rhs) const { return this->t > rhs.t; } //这里一定要const
};

class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int ans = 0, m = grid.size(), n = grid[0].size();
		vector<vector<bool>> vis(m, vector<bool>(n, 0));
		priority_queue<T> que;
		que.push(T(0, 0, grid[0][0]));
		vis[0][0] = 1;
		while (true)
		{
			// 出队 访问，更新高度
			T node = que.top(); que.pop();
			ans = max(ans, node.t);
			if (node.x == n - 1 && node.y == n - 1) return ans;
			for (int i = 0; i < 4; i++)
			{
				int r = node.x + dx[i], c = node.y + dy[i];
				if (r < 0 || r >= m || c < 0 || c >= n || vis[r][c]) continue;
				que.push(T(r, c, grid[r][c]));
				vis[r][c] = 1;
			}
		}

	}
};