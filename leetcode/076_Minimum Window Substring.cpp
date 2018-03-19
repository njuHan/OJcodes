#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0) return "";
		//if (t.size() == 0) return s.substr(0, 1);
		unordered_map<char, int> chCnt;
		// t中重复的字符也必须都在窗口中
		size_t count = t.size(); //窗口中还需添加的t中字符的个数
		for (auto ch : t) chCnt[ch]++; //t中字符计数
		size_t minI = 0, minJ = 0; //窗口起始位置
		size_t minSize = INT_MAX; //最小窗口大小
		size_t i = 0, j = 0;
		while (j < s.size())
		{
			if (chCnt.count(s[j])) //s[j]出现在 t 中
			{
				if (chCnt[s[j]]>0) //大于0，才计数，因为s中可能有很多t中的字符，chCnt可能为负数
					count--;
				chCnt[s[j]]--; //s的窗口中， 字符s[j]还需要出现的次数
				
			}
			j++;
			//当前窗口已经包含了所有t的字符
			//缩小win左侧, 减小窗口
			while (count == 0 && i<j)
			{
				//注意此时的j指向窗口最后一个字符的下一个字符
				if (minSize > j - i)
				{
					minSize = j - i;
					minI = i;
					minJ = j;
				}
				if (chCnt.count(s[i]))
				{
					chCnt[s[i]]++;
					if (chCnt[s[i]] > 0) //说明窗口中缺少 字符 s[i]
						count++;
				}
				i++;
			}
		}
		if (minSize == INT_MAX)
			return "";
		else
			return s.substr(minI, minSize);

	}
};

int main()
{
	Solution solu;
	string s = "abc", t = "";
	string ans = solu.minWindow(s, t);
	cout << ans;
	system("pause");
	return 0;
}