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
	int Sum_Solution(int n) {
		return f(n);
	}
private:
	int f(int n)
	{
		if (n == 1) return 1;
		return f(n - 1) + n;
	}
};