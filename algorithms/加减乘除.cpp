#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;


//为运算实现加法
int add(int a, int b)
{
	if (b == 0) return a;
	int sum, carry;
	sum = a^b; //没有进位的加法
	carry = (a&b) << 1; //有进位的加法,注意括号
	return add(sum, carry);
}

//减法：
//减法转化为加法：a - b = a + (-b) = a + (~b + 1 )
int sub(int a, int b)
{
	return add(a, add(~b, 1));
}

//乘除法中出现的加减可以用add,sub代替
//乘法
int muti(int a, int b)
{
	bool nega = (b < 0);
	if (nega) b = -b; //使得 b 为正数
	unordered_map<int, int> shift;
	for (int i = 0; i < 32; i++)
	{
		shift[1 << i] = i;
	}
	int sum = 0;
	while (b > 0) //遍历 b 的二进制1
	{
		//int last = b&(~b + 1); //取出最后一个1，add
		int last = b&(-b); //-b == (~b+1)
		int temp = shift[last];
		sum = sum + (a << temp); //改为 add()
		b = b&(b - 1); //消去最后一个1， sub
	}
	if (nega) return -sum;
	else return sum;
}

//除法
int mydiv(int a, int b)
{
	if (b == 0) throw std::exception("divider is zero");
	bool nega = (a < 0) ^ (b < 0);
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	if (a < b) return 0;
	int msb = 0;
	while ((b<<msb)<a)
	{
		msb++;
	}
	int res = 0;
	for (int i = msb; i >= 0; i--)
	{
		if ((b << i) > a) continue;
		res = res | (1 << i);
		a = a - (b << i);
	}
	if (nega) return -res;
	else return res;
}



int main()
{

	cout << mydiv(13, 3);
	system("pause");
	return 0;
}
