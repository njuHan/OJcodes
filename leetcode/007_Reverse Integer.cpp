#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class Solution {
public:
	int reverse2(int x) {
		int sign = x < 0 ? -1 : 1;
		x = x < 0 ? -x : x;
		long long ans = 0;
		while (x)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
			if (sign * ans>INT_MAX || sign * ans < INT_MIN) return 0;
		}
		return sign * ans;
	}
	int reverse(int x) {
		int ans = 0, pre;
		while (x)
		{
			pre = ans * 10 + x % 10;
			if (ans != pre / 10) return 0; //overflow
			ans = pre;
			x /= 10;
		}
		return ans;
	}
};