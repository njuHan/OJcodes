#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		int len = num.size();
		if (len <= k)
			return "0";
		vector<int> vec;
		string ans;
		for (int i = 0; i < len; i++)
		{
			//先删除高位的较大数字
			while (vec.size() != 0 && vec[vec.size() - 1]>num[i] && k)
			{
				vec.pop_back();
				k--;
			}
			if (!(vec.size() == 0 && num[i] == '0'))
				vec.push_back(num[i]);
		}
		while (vec.size() != 0 && k)
		{
			vec.pop_back();
			k--;
		}
		if (vec.size() == 0) return "0";
		for (int i = 0; i < vec.size(); i++)
			ans.append(1,vec[i]);
		return ans;
	}

};

int main()
{
	string s = "112";
	int k = 1;
	Solution solu;
	string ans = solu.removeKdigits(s, k);
	cout << ans;
	system("pause");
	return 0;
}