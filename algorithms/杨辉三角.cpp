#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;

const int maxn = 100;
int c[maxn];
int a[maxn][maxn];
/*
组合数：
c(n,k) = c(n,k-1) * (n-k+1)/k
*/
//杨辉三角
//O(n*n):二维数组计算，
void getn2(int n)
{
	for (int i = 0; i <= n; i++)
	{
		a[i][0] = 1;
		for (int j = 1; j <= i; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
}

//O(n):计算第 n 行系数
//c(n,k) = c(n,k-1) * (n-k+1)/k

void getn(int n)
{
	memset(c, 0, sizeof(c));
	c[0] = 1; //c(n,0) = 1;
	cout << c[0];
	for (int i = 1; i <= n; i++)
	{
		c[i] = c[i - 1] * (n - i + 1) / i;
		cout << "," << c[i];
	}
	cout << endl;
}
int main()
{
	for (int i = 0; i <= 7; i++)
		getn(i);
	system("pause");
	return 0;
}
