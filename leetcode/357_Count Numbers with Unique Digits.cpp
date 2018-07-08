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
		// ans[n]: 位数为0到n的UniqueDigits 的个数, 把0看作位数为0
		//pre[n] : 位数为n且第一位不为0的 niqueDigits 的个数
		//n==0, 1特殊情况
		// n==0时，只有 一个 0， ans[0] = 1;
		// n==1时，pre[1]=9, ans[1] = pre[1] + ans[0] = 9+1 =10;
		int ans = 10, pre = 9; //n==1;
		for (int i = 2; i <= min(10, n); i++)
		{
			pre = pre * (10 - i + 1);
			ans = ans + pre;
		}
		return ans;
	}
};