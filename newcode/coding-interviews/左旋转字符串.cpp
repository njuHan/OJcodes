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
using namespace std;
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.length();
		if (len == 0) return str;
		n %= len;
		return str.substr(n) + str.substr(0, n);
	}
};

int main()
{
	Solution solu;
	string ans = solu.LeftRotateString("abcXYZdef", 3);
	cout << ans;
	system("pause");
	return 0;
}