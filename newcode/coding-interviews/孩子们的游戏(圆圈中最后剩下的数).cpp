#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
using namespace std;


class Solution {
public:
	//f(n,m) = (f(n-1,m) + m) % n;
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) return -1;
		int last = 0;
		for (int i = 2; i <= n; i++)
		{
			last = (last + m) % i;
		}
		return last;
	}
};