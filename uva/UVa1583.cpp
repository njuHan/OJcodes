#include <stdio.h>
#include <iostream>
#include <string.h>
const int maxn = 100005;
int ans[maxn];
int main()
{
	memset(ans, 0, sizeof(ans));
	int kase;
	scanf("%d", &kase);
	
	for (int i = 0; i < 100000; i++)
	{
		int sum = i;
		int temp = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum <= 100000 && ans[sum] == 0)
		{
			ans[sum] = i;
		}
	}
	while (kase > 0)
	{
		kase--;
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	
	
	//system("pause");
	return 0;

}
