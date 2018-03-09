#include <stdio.h>
#include <string.h>
#include <iostream>
const int maxn = 105;
char s[maxn];
int get_min(const char* s, int p, int q)
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[(p+i)%n]  > s[(q+i)%n] )
		{
			return q;
		}
		else if (s[(p + i) % n]  < s[(q + i) % n] )
		{
			return p;
		}
	}
	return p;
}
int main()
{
	int kase = 0;
	scanf("%d", &kase);
	while (kase --)
	{
		scanf("%s", &s);
		int min_index = 0;
		int n = strlen(s);
		for (int i = 1; i < n; i++)
		{
			min_index = get_min(s, min_index, i);
		}
		for (int i = 0; i < n; i++)
		{
			printf("%c", s[(min_index+i)%n]);
		}
		printf("\n");


	}
	//system("pause");
	return 0;
}
