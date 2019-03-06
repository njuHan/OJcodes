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
	int StrToInt(string str) {
		int len = str.length();
		if (len < 1) return 0;
		long long ans = 0;
		int sign = 1, i = 0;
		while (str[i] == ' ') i++;
		if (i < len && (str[i] == '-' || str[i] == '+')) sign = str[i++] == '+' ? 1 : -1;
		while (i<len && isdigit(str[i]))
		{
			ans = ans * 10 + (str[i++] - '0');
			if (ans*sign > INT_MAX) return INT_MAX;
			if (ans*sign < INT_MIN) return INT_MIN;
		}
		return i == len ? ans*sign : 0; //需要整个字符串合法
		
	}
};

int main()
{
	Solution solu;
	int ans = solu.StrToInt("123");
	cout << ans << endl;
	int i = string::npos;
	cout << i << endl;
	cout << string::npos;
	system("pause");
	return 0;
}