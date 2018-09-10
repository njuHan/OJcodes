#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 100000;
const int maxn = 100;
int d[maxn];
int u[maxn];
int v[maxn];
int w[maxn];

//bellman ford
int n, m; // 点数 边数
void bellmanFord(int src)
{
	for (int i = 0; i < n; i++) d[i] = (i == src ? 0 : INF);
	//对每条边 松弛 n-1 次
	for (int i=0; i<n-1; i++)
		for (int e = 0; e < m; e++)
		{
			int x = u[e], y = v[e];
			if (d[x]<INF && d[y]> d[x] + w[e])
			{
				d[y] = d[x] + w[e];
			}
		}
}


//使用FIFO队列优化
//源点s到达其他的点的最短路径中的第一条边，必定是源点s相连的边，
//因此，第一次松弛，我们只需要将这些边松弛一下即可。
//第二次松弛的边，必定是第一次松弛的边相邻的边,这是SPFA算法的关键

struct Edge
{
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct BellmanFord
{
	vector<Edge> edges;
	vector<int> G[maxn]; //G[u]存放 从u出发的边
	int n, m;
	int d[maxn];
	bool inq[maxn]; //是否在队列中
	int p[maxn]; //p[i]:最近路径上，结点i的上一条边
	int cnt[maxn]; //结点加入队列次数计数

	void init(int n)
	{
		this->n = n;
		edges.clear();
		for (int i = 0; i < n; i++) G[i].clear();
	}
	void addEdge(int u, int v, int dist)
	{
		edges.push_back(Edge(u, v, dist));
		this->m = edges.size();
		G[u].push_back(this->m - 1);
	}
	bool bellmanford(int src)
	{
		queue<int> que;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) d[i] = (i == src ? 0 : INF);
		inq[src] = 1;
		que.push(src);

		while (!que.empty())
		{
			int u = que.front();  que.pop();
			inq[u] = 0;
			for (int i : G[u])
			{
				Edge& e = edges[i];
				if (d[u] < INF && d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist; //松弛
					p[e.to] = i;  //记录"父边"
					if (inq[e.to] == 0)
					{
						inq[e.to] = 1;
						que.push(e.to);
						if (++cnt[e.to] > n) //判断负环
							return false;
					}
				}
			}
		}
		return true;
	}
};

int main()
{
	int n = 5;
	vector<vector<int>> a(5, vector<int>(5, -1));
	a[0][1] = 10;
	a[1][0] = 10;
	a[0][3] = 30;
	a[3][0] = 30;
	a[0][4] = 100;
	a[4][0] = 100;
	a[1][2] = 50;
	a[2][1] = 50;
	a[2][3] = 20;
	a[3][2] = 20;
	a[2][4] = 10;
	a[4][2] = 10;
	a[3][4] = 60;
	a[4][3] = 60;
	BellmanFord bf;
	bf.init(5);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != -1)
			{
				bf.addEdge(i, j, a[i][j]);
			}
		}
	int src = 0;
	bf.bellmanford(src);
	for (int i = 0; i < n; i++)
		cout << bf.d[i] << ", ";
	cout << endl;

	int node = 4;
	while (node != src)
	{
		int e = bf.p[node];
		cout << bf.edges[e].from << " " << bf.edges[e].to << " " << bf.edges[e].dist << endl;
		node = bf.edges[e].from;
	}

	system("pause");
	return 0;
}
