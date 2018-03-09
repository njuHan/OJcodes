#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100;
double x[maxn], y[maxn], state[maxn][maxn], dist[maxn][maxn];
int n;
double dp(int i, int j)
{
	double& ans = state[i][j];
	if (ans > 0) return ans;
	if (i == n - 2)
	{
		ans = dist[n-1][i] + dist[n-1][j];
	}
	else
	{
		ans = min(dp(i + 1, j) + dist[i + 1][i], dp(i + 1, i) + dist[i + 1][j]);
	}
	return ans;

}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		memset(state, 0, sizeof(state));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				dist[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])* (y[i] - y[j]));

		double ans = dp(1, 0) + dist[1][0];
		printf("%.2lf\n", ans);
	}
	//system("pause");
	return 0;
}