//#define LOCAL
#include<iostream>
using namespace std;


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int n = 0;
	int kase = 1;
	const int maxn = 1010;
	int a[maxn], b[maxn];
	while (scanf("%d", &n) == 1 && n != 0)
	{
		printf("Game %d:\n", kase++);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		while (true)
		{
			int count_a = 0, count_b = 0;
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &b[i]);
				if (b[i] == a[i])
					count_a++;
			}
			if (b[0] == 0)
			{
				break;
			}
			
			for (int d = 1; d <= 9; d++)
			{
				int c1 = 0, c2 = 0;
				for (int i = 0; i < n; i++)
				{
					if (a[i] == d) c1++;
					if (b[i] == d) c2++;

				}
				c1 = (c1 < c2 ? c1 : c2);
				count_b += c1;

			}
			
			printf("    (%d,%d)\n", count_a, count_b - count_a);

		}
	}
	//system("pause");
	return 0;
}
