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

//虚函数
class A
{
public:
	virtual int sum(int n) { return 0; };
};
A* arr[2];
class B : public A
{
public:
	virtual int sum(int n) { return n + arr[!!n]->sum(n - 1); }
};

//函数指针
typedef int (*PF)(int);
PF pf[2];
int sum0(int n) { return 0; };
int sum1(int n) { return pf[!!n](n - 1) + n; }

class Solution {
public:
	int Sum_Solution1(int n) {
		Temp::reset();
		Temp* p = new Temp[n];
		delete []p;
		return Temp::getSum();
	}
	// && 短路运算
	int Sum_Solution2(int n) {
		int ans = n;
		n && (ans += Sum_Solution2(n - 1));
		return ans;
	}
	int Sum_Solution3(int n) {
		A a;
		B b;
		arr[0] = &a;
		arr[1] = &b;
		return b.sum(n);
	}
	int Sum_Solution4(int n) {
		pf[0] = sum0;
		pf[1] = sum1;
		return sum1(n);
	}

};
