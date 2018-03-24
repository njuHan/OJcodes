#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;

/*
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
class Solution {
public:
	string countAndSay(int n) 
	{
		string cur = "1", next;
		if (n < 1) return "";
		while (n-->1)
		{
			next.clear();
			int i = 0;
			while (i < cur.size())
			{
				int times = 0;
				int ch = cur[i];
				while (i<cur.size() && cur[i] == ch)
				{
					i++;
					times++;
				}
				next += to_string(times);
				next.push_back(ch);
			}
			swap(cur, next);
		}
		return cur;
	}
};

int main()
{
	Solution solu;
	string ans = solu.countAndSay(2);
	system("pause");
	return 0;
}