/*
二叉索引数 binary indexed tree (BIT)
给定数组A1， A2, ... ,An
支持两种操作：
Add(x,d): 让Ax 增加 d
query(LR): 计算 AL+...+AR
*/

const int maxn = 105;
int A[maxn+1]; //范围 ： [1,maxn]
int C[maxn+1];
// C[i] = A[i-lowbit(i)+1] + ...+ A[i]

//求下标 x 的lowebit
int lowbit(int x)
{
	return x&(-x);
}

// 按照C 的定义预处理C
void getC()
{
	for (int i = 1; i < maxn; i++)
	{
		C[i] = 0;
		for (int j = i - lowbit(i) + 1; j <= i; j++)
		{
			C[i] += A[j];
		}
	}
}

//sum A[1]+...+A[x]
int sum(int x)
{
	int ans = 0;
	while (x>0)
	{
		ans += C[x];
		x = x - lowbit(x);
	}
	return ans;
}

//update A[x]
void add(int x, int d)
{
	while (x<=maxn)
	{
		C[x] += d;
		x = x + lowbit(x);
	}
}

// 使用 add 预处理 C
// 置零 A,C, 执行maxn次 add
// 更新 A
void initC()
{
	for (int i = 1; i <= maxn; i++)
	{
		add(i, A[i]);
	}
}
