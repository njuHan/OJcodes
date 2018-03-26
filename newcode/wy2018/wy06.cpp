#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

bool isvalid(const string& str)
{
	int cnt = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	return cnt == 0;
}

/*
根据题意，要想使得 LCS 最大，删去任意一个字符即可获得 LCS = |s| - 1 ，再把该字符插到与原来不同的任意位置可以维持原长度，而不影响 LCS 的计算。

因此最暴力的做法是枚举每个字符，把它插入到任意位置，判合法，去重，累计。

优化 1 ：插入是插到指定位置的字符之前，如果插入的字符和该位置的字符相同，则插入后还是原字符串，可以跳过这种情况。否则最后的结果要 - 1 。
优化 2 ：左右两边一定是左右括号，不用移动它们。但字符却可以插到它们的后面。

判合法：实际上就是括号匹配的平衡性。在这里，如果我们从前到后遍历，左括号可以暂时多于右括号，但不可以少于，因为能够闭合右括号的左括号都在左边了。每次成功闭合一对括号把数量 - 1 ，得到负数说明不平衡。
*/

int main()
{
	string str;
	cin >> str;
	
	set<string> ans;
	for (int i = 0; str[i]; i++)
	{
		// erase i
		string strdelei(str);
		strdelei.erase(i,1);
		char chi = str[i];
		// insert at j
		for (int j = 0; str[j]; j++)
		{
			if (chi == str[j]) continue;
			string strinsetj(strdelei);
			strinsetj.insert(j, 1, chi);
			if (isvalid(strinsetj))
				ans.insert(strinsetj);
		}
	}
	cout << ans.size() << endl;
	//system("pause");
	return 0;
}