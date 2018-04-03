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
int d[maxn][maxn];

void floyd(int n)
{
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] < INF && d[k][j] < INF)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
}



int main()
{
	
	int n = 5;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	d[0][1] = 10;
	d[1][0] = 10;
	d[0][3] = 30;
	d[3][0] = 30;
	d[0][4] = 100;
	d[4][0] = 100;
	d[1][2] = 50;
	d[2][1] = 50;
	d[2][3] = 20;
	d[3][2] = 20;
	d[2][4] = 10;
	d[4][2] = 10;
	d[3][4] = 60;
	d[4][3] = 60;
	floyd(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << i << "," << j << ":" << d[i][j] << endl;
		}
	}

	system("pause");
	return 0;
}



