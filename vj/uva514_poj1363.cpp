#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 1010;
int target[maxn];

int main()
{
	int n, temp;
	while (scanf("%d", &n) && n != 0)
	{
		while (scanf("%d",&temp) && temp!=0)
		{
			stack<int> sk;
			target[0] = temp;
			for (int i = 1; i < n; i++)
				scanf("%d", &target[i]);
			int curNum = 1, idx = 0, ok = 1;
			while (idx < n)
			{
				
				if (target[idx] == curNum)
				{
					idx++;
					curNum++;
				}
				else if (!sk.empty() && sk.top() == target[idx])
				{
					idx++;
					sk.pop();
				}
				else if (curNum<=n) //这里使用curnNum<n也行
				{
					sk.push(curNum);
					curNum++;
				}
				else
				{
					ok = 0;
					break;
				}
			}
			if (ok) printf("Yes\n");
			else printf("No\n");
			
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}
