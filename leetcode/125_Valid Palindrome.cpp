#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		string str;
		for (int i = 0; i < s.size(); i++)
		{
			if ('a' <= s[i] && s[i] <= 'z')
				str.push_back(s[i]);
			else if ('A' <= s[i] && s[i] <= 'Z')
				str.push_back(s[i] + 32);
			else if ('0' <= s[i] && s[i] <= '9')
				str.push_back(s[i]);
		}
		int len = str.size();
		int i = 0, j = len - 1;
		while (i < j)
		{
			if (str[i++] != str[j--])
				return false;
		}
		return true;
	}
};

int main()
{
	int a = 'a';
	int b = 'A';
	cout << a << " " << b<<" "<<a-b;
	system("pause");
	return 0;
}