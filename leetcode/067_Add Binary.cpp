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
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		stack<char> sk;
		int more = 0, m = a.size()-1, n = b.size()-1;
		while (m>=0 || n>=0)
		{
			int temp = more;
			if (m >= 0) temp += a[m--]-'0';
			if (n >= 0) temp += b[n--]-'0';
			sk.push((temp % 2)+'0');
			more = temp / 2;
		}
		if (more) sk.push(more + '0');
		string ans;
		while (sk.size() > 1 && sk.top() == '0')
			sk.pop();
		while (!sk.empty())
		{
			ans.push_back(sk.top());
			sk.pop();
		}
		return ans;
	}
};
int main()
{
	Solution s;
	string ans = s.addBinary("11", "1");
	system("pause");
	return 0;
}