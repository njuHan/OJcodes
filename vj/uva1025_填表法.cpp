#include<iostream>
#include<cstring>
#include<algorithm>
#include<assert.h>
using namespace std;

const int maxn = 50 + 5;
const int maxt = 200 + 5;
const int INF = 1000000000;

// has_train[t][i][0]表示时刻t，在车站i是否有往右开的火车
int trainTime[maxn], has_train[maxt][maxn][2];
int dp[maxt][maxn];
bool vis[maxt][maxn];
int T, n;

int search(int t, int i)
{
	int& ans = dp[t][i];
	//注意！这里不能用 if(ans<INF)判断, 会重复访问结点
	if (vis[t][i]) return ans;
	vis[t][i] = 1;
	if (t < T)
		ans = min(ans, search(t + 1, i) + 1);
		//ans = search(t + 1, i) + 1;
	if (i < n && has_train[t][i][0] && t + trainTime[i] <= T)
		ans = min(ans, search(t + trainTime[i], i + 1));
	if (i > 1 && has_train[t][i][1] && t + trainTime[i - 1] <= T)
		ans = min(ans, search(t + trainTime[i - 1], i - 1));
	//if (ans < INF)
	//printf("(%d, %d),ans = %d\n", t, i, ans);
	return ans;
}

int main() {
	int kase = 0;
	while (cin >> n  && n) 
	{
		cin >> T;
		int M1, M2, d;
		for (int i = 1; i <= n - 1; i++) cin >> trainTime[i];

		// 预处理，计算has_train数组
		memset(has_train, 0, sizeof(has_train));
		cin >> M1;
		while (M1--) {
			cin >> d;
			for (int j = 1; j <= n - 1; j++) {
				if (d <= T) has_train[d][j][0] = 1;
				d += trainTime[j];
			}
		}
		cin >> M2;
		while (M2--) {
			cin >> d;
			for (int j = n - 1; j >= 1; j--) {
				if (d <= T) has_train[d][j + 1][1] = 1;
				d += trainTime[j];
			}
		}

		for (int t = 0; t <= T; t++)
			for (int i = 1; i <= n; i++) 
				dp[t][i] = INF;
		memset(vis, 0, sizeof(vis));
		dp[T][n] = 0;//到达终点的条件
		
	
		cout << "Case Number " << ++kase << ": ";
		if (search(0,1) >= INF) cout << "impossible\n";
		else cout << search(0,1) << "\n";
	

	}
	return 0;
}
