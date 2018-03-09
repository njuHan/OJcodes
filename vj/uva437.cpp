#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 30 + 5;
int n, blocks[maxn][3], d[maxn][3];

void get_dimensions(int* v, int b, int dim) {
	int idx = 0;
	for (int i = 0; i < 3; i++)
		if (i != dim) v[idx++] = blocks[b][i];
}

//dp(i,j)表示：以dp(i,j)为塔的最下面（最大）的立方体时，
//塔的总高度；
int dp(int i, int j) {
	int& ans = d[i][j];
	if (ans > 0) return ans; //记忆，已经算过
	ans = blocks[i][j]; //总高度的最小值，即只有(i,j)一个立方体的塔
	int v[2], v2[2];
	get_dimensions(v, i, j);
	//遍历所有比(i,j)小的立方体，即可以放在(i,j)上面的立方体(a,b)
	for (int a = 0; a < n; a++)
		for (int b = 0; b < 3; b++)
		{
			get_dimensions(v2, a, b);
			if (v2[0] < v[0] && v2[1] < v[1]) ans = max(ans, dp(a, b)+blocks[i][j]);
		}
	return ans;
}

int main() {
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
				scanf("%d", &blocks[i][j]);
			sort(blocks[i], blocks[i] + 3);
		}
		memset(d, 0, sizeof(d));
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				ans = max(ans, dp(i, j));
		printf("Case %d: maximum height = %d\n", ++kase, ans);
	}
	system("pause");
	return 0;
}
