#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
// POJ1915_Knight Moves	 

using namespace std;

const int maxn = 300;
int board[maxn][maxn];
bool vis[maxn][maxn];

int di[] = { -2,-1,-2,-1, 1, 2, 1, 2 };
int dj[] = { -1,-2, 1, 2,-2,-1, 2, 1 };

struct Location
{
	int x, y, cnt;
	Location(int x = 0, int y = 0, int cnt = 0) :x(x), y(y), cnt(cnt) {}
};

int main()
{
	int n, l, x, y, endx, endy;
	cin >> n;
	while (n-->0)
	{
		memset(vis, 0, sizeof(vis));
		cin >> l;
		cin >> x >> y;
		cin >> endx >> endy;
		queue<Location> que;
		que.push(Location(x,y,0));
		vis[x][y] = 1;
		int cnt = 0;
		bool flag = false;
		while (!que.empty())
		{		
			Location loc = que.front(); que.pop();
			if (loc.x == endx && loc.y == endy)
			{
				printf("%d\n", loc.cnt);
				break;
			}
			Location next(0,0,loc.cnt+1);
			for (int i = 0; i < 8; i++)
			{
				next.x = loc.x + di[i];
				next.y = loc.y + dj[i];
				if (next.x >= l || next.y >= l || next.x <0 || next.y < 0 || vis[next.x][next.y])
					continue;
				else
				{
					que.push(next);
					vis[next.x][next.y] = 1;
				}
			}
		}
	}

	return 0;
}