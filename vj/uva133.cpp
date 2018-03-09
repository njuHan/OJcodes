#include<stdio.h>
#include<string.h>
const int maxn = 25;
int a[maxn];

int go(int start, int step, int num,int a[], int N)
{
	int p = start;
	while (num--)
	{
		do
		{
			p = (p + N + step) % N;
		} while (a[p] == 1);
	}
	return p;
}

int main()
{
	int N, k, m;
	int flag = 1;
	while (scanf("%d%d%d", &N, &k, &m) == 3 && (N && k && m))
	{
		int left = N;
		int start1 = 0 -1;
		int start2 = N - 1 +1;
		memset(a, 0, sizeof(a));
		while (left)
		{
			if (flag == 1)
			{
				flag = 0;
			}
			else
			{
				printf(",");
			}
			start1 = go(start1, 1, k, a, N);
			start2 = go(start2, -1, m, a, N);
			//printf("%d,%d***", start1, start2);
			if (start1 == start2)
			{
				left -= 1;
				a[start1] = 1;
				printf("%3d", start1+1);
			}
			else
			{
				left -= 2;
				a[start1] = 1;
				a[start2] = 1;
				printf("%3d", start1+1);
				printf("%3d", start2+1);
			}
			

		}
		printf("\n");
		flag = 1;
	}
}
