#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
#include<sstream>
using namespace std;
class Solution {
public:
	//利用sstream 自动划分char int
	//遇到+或-，将当前计算值cur加入总值total，更新cur
	//
	int calculate(string s) {
		int total = 0; 
		int cur = 0;
		istringstream in(s);
		in >> cur;
		char op;
		while (in >> op)
		{
			if (op == '+' || op == '-')
			{
				total += cur;
				in >> cur;
				if (op == '-') cur = -cur;
			}
			else
			{
				int temp;
				in >> temp;
				if (op == '*') cur *= temp;
				else cur /= temp;
			}
		}
		return total + cur;
	}
};
int main()
{
	Solution solu;
	int ans = solu.calculate("  10 + 2 * 10");
	string str = "10*3010";
	istringstream is(str);
	string s;
	char ch;
	int n1, n2;
	is >> n1;
	is >> ch;
	is >> n2;
	system("pause");
	return 0;
}