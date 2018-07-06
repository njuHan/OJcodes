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

const int maxn = 105;
int m; //edge num
struct Edge
{
	int from, to, dist;
	Edge(int f, int t, int d) :from(f), to(t), dist(d) {}
};

struct Node
{
	int d, u;
	Node(int d, int u) :d(d), u(u) {}
	bool operator < (const Node& rhs) const // ±ØÐëÓÐconst
	{
		return d > rhs.d;
	}
};

vector<Edge> edges;
vector<int> G[maxn];
int d[maxn];
bool done[maxn];

void add(int u, int v, int d)
{
	edges.push_back(Edge(u, v, d));
	m = edges.size();
	G[u].push_back(m - 1);
}


// dijkstra with priority q
//44ms
class Solution {
public:
	// There are N network nodes, labelled 1 to N.
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		// initail global var
		memset(done, 0, sizeof(done));
		edges.clear();
		for (int i = 0; i < maxn; i++) G[i].clear();
		priority_queue<Node> que;
		// initial dist
		for (int i = 1; i <= N; i++) d[i] = (i == K ? 0 : INT_MAX);
		// add edges
		for (auto e : times) add(e[0], e[1], e[2]);
		que.push(Node(0, K));
		while (!que.empty())
		{
			Node node = que.top(); que.pop();
			if (done[node.u]) continue;
			done[node.u] = 1;
			int u = node.u;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if (d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.dist)
				{
					d[e.to] = d[e.from] + e.dist;
					que.push(Node(d[e.to], e.to));
				}
			}

		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (d[i] == INT_MAX) return -1;
			ans = max(ans, d[i]);
		}
		return ans;
	}
};

bool inq[maxn];
int cnt[maxn];
// bellman ford, spfa
//36ms
class Solution2 {
public:
	// There are N network nodes, labelled 1 to N.
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		memset(inq, 0, sizeof(inq));
		//memset(cnt, 0, sizeof(cnt));
		edges.clear();
		for (int i = 0; i < maxn; i++) G[i].clear();

		for (int i = 1; i <= N; i++) d[i] = (i == K ? 0 : INT_MAX);
		for (auto e : times) add(e[0], e[1], e[2]);
		queue<int> que;
		que.push(K);
		while (!que.empty())
		{
			int u = que.front(); que.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if (d[u]<INT_MAX && d[e.to] > d[e.from] + e.dist)
				{
					d[e.to] = d[e.from] + e.dist;
					if (inq[e.to] == 0)
					{
						que.push(e.to);
						inq[e.to] = 1;
						//if (++cnt[e.to] > N) return -1; // has negative cycle
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (d[i] == INT_MAX) return -1;
			ans = max(ans, d[i]);
		}
		return ans;
	}
};

int main()
{
	Solution solu;
	return 0;
}