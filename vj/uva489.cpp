#include<stdio.h>
#include<string.h>  

const int maxn = 105;
const int chance = 7;
char s[maxn];
char s2[maxn];
int left, error, lose, win;

void guess(char c)
{
	int m = strlen(s);
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == c)
		{
			left--;
			flag = 1;
			s[i] = ' ';
			if (left == 0)
				win = 1;
		}
		
	}
	if (flag == 0)
	{
		error++;
		if (error >= chance)
			lose = 1;
	}
}

int main()
{
	int rnd;
	while (scanf("%d", &rnd) == 1 && rnd != -1)
	{
		scanf("%s", s);
		scanf("%s", s2);
		int m = strlen(s);
		int n = strlen(s2);
		left = m;
		error = 0;
		win = lose = 0;
		for (int i = 0; i < n; i++)
		{
			guess(s2[i]);
			if (win || lose)
				break;
		}
		printf("Round %d\n", rnd);
		if (win)
		{
			printf("You win.\n");
		}
		else if (lose)
		{
			printf("You lose.\n");
		}
		else
		{
			printf("You chickened out.\n");
		}
	

	}
}
