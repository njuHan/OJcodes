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
	void reverseWords(string &s) {
		int len = s.length();
		if (len == 0) return;
		int toinsert=0, begin = 0, end;
	
		for (int begin = 0; begin < len; begin++)
		{
			if (s[begin] != ' ')
			{
				if (toinsert != 0) toinsert++;
				for (end = begin; end < len && s[end] != ' '; end++);
				reverse(&s[toinsert], &s[end]);
				toinsert += (end - begin);
				begin = end;
			}
		}
		s.erase(toinsert, len - toinsert);
		reverse(s.begin(), s.end());
	}
};

int main()
{
	Solution solu;
	string s = "   abc   def gh ";
	solu.reverseWords(s);
	cout << s;
	system("pause");
	return 0;
}