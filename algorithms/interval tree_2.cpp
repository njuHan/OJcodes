#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

#define lson(rt) (rt<<1)
#define rson(rt) (rt<<1|1)
#define mid(l,r) (l + ((r-l)>>1))

const int maxn = 100;
int a[maxn], sum[maxn << 2], add[maxn << 2];

//向上更新结点
void pushUp(int rt)
{
	sum[rt] = sum[lson(rt)] + sum[rson(rt)];
}
//向下推区间更新标记
void pushDown(int rt, int ln, int rn)
{
	if (add[rt])
	{
		add[lson(rt)] += add[rt];
		add[rson(rt)] += add[rt];
		sum[lson(rt)] += ln*add[lson(rt)];
		sum[rson(rt)] += rn*add[rson(rt)];
		add[rt] = 0;
	}
}

//建树
void build(int l, int r, int rt)
{
	if (l == r)
	{
		sum[rt] = a[l];
		return;
	}
	int m = mid(l, r);
	build(l, m, lson(rt));
	build(m + 1, r, rson(rt));
	pushUp(rt);
}

//点增量修改
void update(int x, int c, int l, int r, int rt) //有效调用时必须x在区间[l,r]内
{
	if (l==r) //叶结点，直接修改
	{
		sum[rt] += c;
		return;
	}
	int m = mid(l, r);
	pushDown(rt, m - l + 1, r - m);
	if (x <= m) update(x, c, l, m, lson(rt));
	else update(x, c, m + 1, r, rson(rt));
	pushUp(rt);
}

//区间增量修改 [x,y]区间的数+c
void update(int x, int y, int c, int l, int r, int rt) 
{
	if (x <= l && r <= y) //完全覆盖该结点区间
	{
		sum[rt] += c * (r - l + 1);
		add[rt] += c;
		return;
	}
	int m = mid(l, r);
	//如果题目中是点修改和区间修改混合的话，那么点修改中也需要PushDown。
	pushDown(rt, m - l + 1, r - m);
	if (x <= m) update(x, y, c, l, m, lson(rt));
	if (y >= m + 1) update(x, y, c, m + 1, r, rson(rt));
	pushUp(rt);
}

int query(int x, int y, int l, int r, int rt)
{
	if (x <= l && r <= y)
	{
		return sum[rt];
	}
	int m = mid(l, r);
	pushDown(rt, m - l + 1, r - m);
	int ans = 0;
	if (x <= m) ans += query(x, y, l, m, lson(rt));
	if (y >= m + 1) ans += query(x, y, m + 1, r, rson(rt));
	return ans;
}

int main()
{
	int n = 3;
	build(0, n - 1, 1);
	update(0, n - 1, 2, 0, n - 1, 1);
	update(0, 2, 0, n - 1, 1);
	
	int ans = query(0, n-1,0,  n - 1, 1);
	cout << ans;
	system("pause");
	return 0;
}



