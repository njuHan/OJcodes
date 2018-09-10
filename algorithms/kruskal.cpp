#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


const int m = 100; // edge num
const int n = 100; //node num
int w[m];  // edge weights
int r[m];  //sorted edge index
int p[n];  //union find set
int u[m];  //edge(u,v)
int v[m];

//间接排序， 排序后， 从权重小的边的下标 到 权重大的边的下标
int cmp(const int& i, const int& j)
{
	return w[i] < w[j];
}

int findSet(int x)
{
	return x == p[x] ? x : p[x] = findSet(p[x]);
}

int kruskal()
{
	for (int i = 0; i < n; i++) p[i] = i;  //初始化连通分量
	for (int i = 0; i < m; i++) r[i] = i; //初始化边下标
	sort(r, r + m, cmp); //间接排序

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int e = r[i];
		int x = findSet(u[e]), y = findSet(v[e]);
		if (x != y)
		{
			p[x] = y;
			ans += w[e];
		}
	}
	return ans;
}

int main() {



	system("pause");
	return 0;
}
