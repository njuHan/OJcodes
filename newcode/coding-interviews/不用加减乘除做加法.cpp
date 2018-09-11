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
	int Add(int num1, int num2)
	{
		if (num2 == 0) return num1;
		int a = num1^num2;
		num2 = (num1&num2) << 1;
		return Add(a, num2);
	}
};
