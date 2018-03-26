#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 55;
int x[maxn];
int y[maxn];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i]; //x
	for (int i = 0; i < n; i++) cin >> y[i];
	int ans = 0;
	//选两个点i,j，连一条线
	if (n < 4)
	{
		cout << n << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		//i<j, 防止重复
		for (int j = i + 1; j < n; j++)
		{
			int dx1 = x[i] - x[j], dy1 = y[i] - y[j];
			// p不在i,j的直线上
			for (int p = 0; p < n; p++)
			{
				if (p == i || p == j) continue;
				int cnt = 3;
				for (int q = 0; q < n; q++)
				{
					if (q == p || q == i || q == j) continue;
					int dx2 = x[q] - x[i], dy2 = y[q] - y[i];
					int dx3 = x[q] - x[p], dy3 = y[q] - y[p];
					if (dx2 * dy1 == dy2* dx1 || dx3*dx1 + dy3*dy1 == 0) cnt++;
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}


