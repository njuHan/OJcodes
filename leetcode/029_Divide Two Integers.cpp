#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;


class Solution {
public:
	/*
	-2147483648
	-1
	*/

	int divide(int dividend, int divisor) {
		long long a = dividend, b = divisor, res = 0, one = 1;
		bool nega = (a < 0) ^ (b < 0);
		a = a < 0 ? -a : a;
		b = b < 0 ? -b : b;
		if (a < b) return 0;
		int msb = 0;
		while ((b << msb)<a)
		{
			msb++;
		}
		for (int i = msb; i >= 0; i--)
		{
			if ((b << i) > a) continue;
			res = res | (one << i); //这里若用(1<<i) 当i==31时，变成负数
			a = a - (b << i);
		}
		//if (nega) return -res;
		//else return res;
		res = nega ? -res : res;
		res = res < INT_MIN ? INT_MIN : res;
		res = res > INT_MAX ? INT_MAX : res;
		return res;
	}
	
};

int main()
{
	Solution solu;
	solu.divide(-2147483648, -1);
	system("pause");
	return 0;
}
