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
	string ReverseSentence(string str) {
		int i = 0, j, len = str.length();
		while (i < len)
		{
			if (str[i] == ' ') i++;
			else
			{
				for (j = i; j < len && str[j] != ' '; j++);
				reverse(str.begin() + i, str.begin() + j);
				i = j;
			}
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	Solution solu;
	string ans = solu.ReverseSentence("student. a am I");
	cout << ans;
	system("pause");
	return 0;
}