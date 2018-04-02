#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
范围最小值问题 range minimum query (RMQ)
查询 范围[L,R]的最小值：  min{A[L], ..., A[R]}
d[i][j]: 从 A[i]开始， 长度为1<<j的范围的最小值 [i, i+(1<<j)-1]
*/

const int maxn = 100;
//int A[n];
vector<int> A;
int d[maxn][maxn+1];
//预处理 O(nlogn)
void RMQ_init(const vector<int> A)
{
	int n = A.size();
	for (int i = 0; i < n; i++) d[i][0] = A[i]; //j==0

	for (int j = 1; (1 << j) <= n; j++)   
	{
		for (int i=0; i+(1<<j)-1 < n; i++)
		{
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);  
		}
	}
}
//查询O(1)
int rmq(int L, int R)
{
	int k = 0;
	// find the max k s.t. (1<<k) <= R-L+1
	while (1 << (k + 1) <= R - L + 1) k++;

	return min(d[L][k], d[R - (1 << k) + 1][k]); 

}

int main() {



	system("pause");
	return 0;
}
