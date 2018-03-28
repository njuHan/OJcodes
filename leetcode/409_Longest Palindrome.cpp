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


class Solution {
public:
	int longestPalindrome(string s) 
	{
		int oddnum = 0;
		int ans = 0;
		for (char ch : s)
		{
			dict[ch]++;
		}
		for (auto p : dict)
		{
			if (p.second % 2 == 0) //even
			{
				ans += p.second;
			}
			else
			{
				oddnum++;
				ans += (p.second - 1);
			}
		}
		return oddnum > 0 ? ans + 1 : ans;
	}
private:
	map<char,int> dict;
};

int main()
{
	
	
	system("pause");
	return 0;
}

