/*
汉罗塔问题， 把n个圆盘从 A 移动到 B， 借助 C
输出 圆盘序号 ： 移动原地址 -> 目的地址
hanoi(A,B,C,n)
case n==1 :  一个圆盘从A到B (原子操作)
case n>1  :
	1. 把n-1个圆盘从A到C (子问题)
	2. 把第n个圆盘从A到B (原子操作)
	3. 把n-1个圆盘从C到B (子问题)
*/
// call hanoi(A,B,C, n);
void hanoi(char x, char y, char z, int n)
{
	if (n == 1)
		cout << "1: " << x << "->" << y << endl;
	else
	{
		hanoi(x, z, y, n - 1);
		cout << n << ": " << x << "->" << y << endl;
		hanoi(z, y, x, n - 1);
	}
}
