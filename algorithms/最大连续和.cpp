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

const int maxn = 100;
int a[maxn];
//sum a[l] + ... + a[r]

//O(n*n)
//S[i] = a[0]+...+a[i-1], 从0开始连续i个元素
int s[maxn];
int maxsum(int l, int r)
{
	s[0] = 0;
	for (int i = 1; i <= maxn; i++) s[i] = s[i - 1] + a[i-1];
	int sum = s[1];
	for (int i = 1; i <= maxn; i++)
		for (int j = 0; j < i; j++)
			sum = max(sum, s[i] - s[j]);
	return sum;
}

//二分递归 O(nlogn)
int maxsum(int l, int r) //左闭右开区间[l,r)求最大连续和
{
	if (1 == r - l) return a[l];
	//二分：
	int m = l + (r - l) / 2; //[l,m) , [m, r)
	int best = max(maxsum(l, m), maxsum(m, r));
	//找中间点m的最大连续和
	int lhs = a[m-1], rhs = a[m]; //注意这里初始化不能为0,防止负数数组
	int suml=0, sumr=0;
	//这部分可以只要O(1)， 	//https://leetcode.com/problems/maximum-subarray/discuss/20360/C++-An-clear-O(n)-divide-and-conquer-solution-with-comments
	for (int i = m - 1; i >= l; i--)
	{
		lhs = max(lhs, suml += a[i]);
	}
	for (int i = m; i < r; i++)
	{
		rhs = max(rhs, sumr += a[i]);
	}
	best = max(best, lhs + rhs);
	return best;
}

int main()
{



	system("pause");
	return 0;
}
