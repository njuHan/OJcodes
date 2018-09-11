#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) 
	{
		int len = s.size();
		if (len <= 1) return s;
		int maxLen = 0, left, right;
		
		for (int i = 0; i < len; i++)
		{
            if (maxLen >= (len - i) * 2) break; //提前结束
			//选定中心点
			char curCh = s[i];
			int lSame = i, rSame = i;
			// 找到左边重复的 curCh
			while ( 0 <= lSame-1  && s[lSame-1] == curCh)
				lSame -= 1;
			while (rSame + 1 < len && s[rSame + 1] == curCh)
				rSame += 1;
			// 找对称相同元素
			while (lSame - 1 >= 0 && rSame + 1 < len && s[lSame - 1] == s[rSame + 1])
			{
				lSame -= 1;
				rSame += 1;
			}
			int curLen = rSame - lSame + 1;
			if (maxLen < curLen)
			{
				maxLen = curLen;
				left = lSame, right = rSame;
			}

		}
		return s.substr(left, maxLen);
	}
	
};

int main()
{
	Solution solu;
	string ans = solu.longestPalindrome("babad");

	system("pause");
	return 0;
}