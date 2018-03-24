#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.size();
		if (len < 1) return 0;
		long long ans = 0;
		int indicator = 1;
		int i = 0;
		while (str[i] == ' ') i++;// 若全为空格，返回i==len
		//i = str.find_first_not_of(' '); // 若全为空格返回i==-1
		if (i<len && (str[i] == '+' || str[i] == '-')) indicator = str[i++] == '-' ? -1 : 1;
		while (i < len && isdigit(str[i]))
		{
			ans = ans * 10 + (str[i++] - '0');
			if (ans*indicator >= INT_MAX) return INT_MAX;
			if (ans*indicator <= INT_MIN) return INT_MIN;
		}
		return ans*indicator;
	}
};

int main()
{
	Solution solu;
	int ans = solu.myAtoi(" -   ");
	system("pause");
	return 0;
}