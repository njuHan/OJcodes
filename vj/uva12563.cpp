#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 51;
const int maxt = maxn * 180 + 678;
//实现d[maxn][maxt]，由于递推只需要记录上一层的信息，所以只需要两行
//d[i][j]表示: 从第1,2...i首歌中选择，总可唱时间为j,那么可以最多唱d[i][j]首
int d[2][maxt];
int len[maxn];
int main()
{
	int kase, T;
	scanf("%d", &T);
	for (kase = 1; kase <= T; kase++)
	{
		int n, t;
		scanf("%d%d", &n, &t);
		for (int i = 1; i <= n; i++)
			scanf("%d", &len[i]);
		//对于d[0][i],由于题意必须一开始就唱，不能开始有空闲时间
		//所以当i不等于0时，d[0][i]不可取，设置为-1；
		//for (int i = 0; i < maxt; i++) d[0][i] = 0;
		//若把d[0][i]都等于0，那么会导致总时间变长（加上了空闲时间），总时间：t-1+678
		memset(d, -1, sizeof(d));
		d[0][0] = 0;
		int p = 1, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < t; j++) //注意这里不取=t
			{
				d[p][j] = d[p ^ 1][j]; //不选第i首歌
				if (j >= len[i] && d[p ^ 1][j - len[i]] != -1)
				{
					d[p][j] = max(d[p][j], d[p ^ 1][j - len[i]] + 1);
				}
				ans = max(ans, d[p][j]);
			}
			p = p^1; 
		}
		for (int i = t - 1; i >= 0; i--)
		{
			if (d[p^1][i] == ans)
			{
				printf("Case %d: %d %d\n", kase, ans + 1, i + 678);
				break;
			}
		}
	}
	//system("pause");
	return 0;

}