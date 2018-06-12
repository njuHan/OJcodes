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


class Temp
{
public:
	Temp()
	{
		sum += ++n;
	}
	static void reset()
	{
		sum = 0;
		n = 0;
	}
	static int getSum()
	{
		return sum;
	}
private:
	static int sum;
	static int n;
};
int Temp::n = 0;
int Temp::sum = 0;

class Solution {
public:
	int Sum_Solution1(int n) {
		Temp::reset();
		Temp* p = new Temp[n];
		delete []p;
		return Temp::getSum();
	}
	int Sum_Solution2(int n) {
		int ans = n;
		n && (ans += Sum_Solution2(n - 1));
		return ans;
	}
};
