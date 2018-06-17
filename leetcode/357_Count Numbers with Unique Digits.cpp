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
#include<sstream>
#include<functional>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n <= 0) return 1;
		// ans: 位数为1到n的UniqueDigits 的个数
		//pre : 位数为n的 niqueDigits 的个数
		int ans = 10, pre = 9; //n==1;
		for (int i = 2; i <= min(10, n); i++)
		{
			pre = pre * (10 - i + 1);
			ans = ans + pre;
		}
		return ans;
	}
};