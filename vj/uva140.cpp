#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 10;

int main()
{
	char line[265];
	int pos[maxn], letter[maxn];
	int id[256];
	
	while (scanf("%s", line) == 1 && line[0] != '#')
	{
		int n = 0;
		for (int i = 'A'; i <= 'Z'; i++)
			if (strchr(line, i) != NULL)
			{
				id[i] = n++;
				letter[id[i]] = i;
			}
		char* p = line;
		vector<int> u, v;
		while (*p != '\0')
		{
			char nodeu = *p;
			p += 2;
			while (*p != ';' && *p != '\0')
			{
				u.push_back(id[nodeu]);
				v.push_back(id[*p]);
				p++;
			}
			if (*p != '\0') p++;
		}

		int s[maxn], minS[maxn], minBD = n;
		for (int i = 0; i < n; i++) s[i] = i;
		do
		{
			int bd = 0;
			for (int i = 0; i < n; i++) pos[s[i]] = i;
			for (int i = 0; i < u.size(); i++)
			{
				bd = max(abs(pos[u[i]] - pos[v[i]]), bd);
				if (bd >= minBD) break;
			}
			if (bd < minBD)
			{
				minBD = bd;
				memcpy(minS, s, sizeof(s));
			}
		} while (next_permutation(s, s + n));
		for (int i = 0; i < n; i++)
			printf("%c ", letter[minS[i]]);
		printf("-> %d\n", minBD);
	}
	
	//system("pause");
	return 0;
}
