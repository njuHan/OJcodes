#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int s[maxn];
int K, L;
int cnt = 0;

bool isValid(int n, int s[])
{
	for (int j = 1; 2 * j <= n; j++)
	{
		int i;
		for (i = 0; i < j; i++)
		{
			if (s[n - j + i] != s[n - 2 * j + i])
				break;
		}
		if (i == j)
			return false;

	}
	return true;
}

bool dfs(int n)
{
	if (cnt == K)
	{
		for (int i = 0; i < n; i++)
		{
			if (i != 0 && i % 64 == 0)
				printf("\n");
			else if (i != 0 && i % 4 == 0)
				printf(" ");
			printf("%c", s[i] + 'A');

		}
		printf("\n%d\n", n);
		return true;
	}
	else
	{
		for (int i = 0; i < L; i++)
		{
			s[n] = i;
			if (isValid(n + 1, s))
			{
				cnt++;
				if (dfs(n + 1))
				{
					return true;
				}
			}
		}
		return false;
	}
}

int main()
{
	while (scanf("%d%d", &K,& L)==2)
	{
		if (K == 0 || L == 0)
			return 0;
		cnt = 0;
		dfs(0);
	}
	system("pause");
	return 0;
	
}
