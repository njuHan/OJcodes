#include <iostream>
#include <cstdio>
#include<assert.h>
using namespace std;

// permutation and combination
const int maxn = 10;
const int mod = 1000000007;
//定义计算c(n,r) = n!/r!/(n-r)! = (r+1) * ... *n/ (1 * ... * n-r)
long long comb1(int n, int r)
{
	if (n < r) swap(n, r);
	r = r < n - r ? n - r : r;
	long long ans = 1;
	int i = r + 1, j = 1;
	while (i <= n ) // (i <= n && j <= n - r) : i,j的长度一样的 n-(r+1), n-r-1
	{
		ans = ans * i++;
		ans = ans / j++;
	}
	return ans;
}

//递推计算并存储组合数
// c(n,r) = c(n-1,r) + c(n-1, r-1)
long long comb[maxn][maxn];
void getComb()
{
	for (int n = 0; n < maxn; n++)
	{
		comb[n][0] = comb[n][n] = 1;
		for (int r = 1; r < n; r++)
		{
			comb[n][r] = comb[n - 1][r] + comb[n - 1][r - 1];
			// comb[n][r] %= mod; //防溢出取模
		}
	}
}

void getComb2() 
{
	for (int i = 0; i < maxn; i++) 
	{
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) 
		{
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
}


// 排列：
long long permutation[maxn][maxn];
//定义计算A(n,r) = n!/(n-r)!;
long long permu(int n, int r)
{
	if (n < r) swap(n, r);
	long long ans = 1;
	int i = n - r + 1;
	while (i <= n) ans *= i++;
	return ans;
}

//递推 A(n,r) = A(n-1, r) + r*A(n-1,r-1)
long long permus[maxn][maxn];
void getPermus()
{
	for (int n = 0; n < maxn; n++)
	{
		permus[n][0] = 1;
		for (int r = 1; r <= n; r++) //注意A(n,n)要单独讨论
		{
			if (r == n)
				permus[n][r] = r*permus[n - 1][r - 1];
			else
				permus[n][r] = permus[n - 1][r] + r*permus[n - 1][r - 1];
		}
	}
}

int main()
{
	/*
	getComb();
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j <= i; j++)
		{
			int t1 = comb[i][j], t2 = comb1(i, j);
			printf("%d==%d\n", t1, t2);
			assert(t1 == t2);
		}
	*/
	getPermus();
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j <= i; j++)
		{
			int t1 = permus[i][j], t2 = permu(i, j);
			printf("%d==%d\n", t1, t2);
			assert(t1 == t2);
		}
	system("pause");
	return 0;
}