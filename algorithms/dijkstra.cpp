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

//dijkstra 基础版 O(n*n):
int w[maxn][maxn]; //w[u][v]: weight of (u,v)
bool vis[maxn]; // is visited
int d[maxn];
// source node: src
void dijkstraBase(int src)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < maxn; i++) d[i] = (i == src ? 0 : INF);
	int x, m = INF;
	for (int node = 0; node<maxn; node ++)
	{
		m = INF;
		for (int i = 0; i < maxn; i++)
		{
			if (vis[i]==0 && d[i] <= m)
			{
				m = d[x = i];
			}
		}
		vis[x] = 1;
		for (int i = 0; i < maxn; i++)
		{
			if (w[x][i] < INF)
				d[i] = min(d[i], d[x] + w[x][i]);
		}
	}
	
}

//存储每个结点出发的边，利用优先队列，选择d[]最小的结点
//O(mlogn)
struct Edge
{
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};

struct HeapNode
{
	int d, u;
	HeapNode(int d, int u) :d(d), u(u) {}
	//优先级<符号， 优先级大的放队列首
	bool operator < (const HeapNode& rhs) const // 这里必须有const
	{
		return d > rhs.d; // d值较大的优先级低， 放队列靠后
	}
};
struct Dijkstra
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn]; //最短路径的上一条边

	void init(int n)
	{
		this->n = n;
		this->edges.clear();
		for (int i = 0; i < n; i++) G[i].clear();
	}

	void addEdge(int u, int v, int dist)
	{
		edges.push_back(Edge(u, v, dist));
		this->m = edges.size();  //获取新边的下标，同时记录边数m
		G[u].push_back(this->m - 1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode> que;
		// initial
		for (int i = 0; i < n; i++) d[i] = (i == s ? 0 : INF);
		memset(done, 0, sizeof(done));
		que.push(HeapNode(0,s));
		while (!que.empty())
		{
			HeapNode x = que.top(); que.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i : G[u]) // i : idex of edge (u, )
			{
				Edge& e = edges[i];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = i;
					que.push(HeapNode(d[e.to], e.to));
				}
			}
		}

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
	Dijkstra dij;
	dij.init(5);
	for (int i=0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != -1)
			{
				dij.addEdge(i, j, a[i][j]);
			}
		}
	int src = 0;
	dij.dijkstra(src);
	for (int i = 0; i < n; i++)
		cout << dij.d[i] << ", ";
	cout << endl;

	int node = 4;
	while (node != src)
	{
		int e = dij.p[node];
		cout << dij.edges[e].from << " " << dij.edges[e].to << " " << dij.edges[e].dist << endl;
		node = dij.edges[e].from;
	}

	system("pause");
	return 0;
}



