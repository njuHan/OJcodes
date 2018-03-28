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
	/*
	pattern = "abba", str = "dog cat cat dog" should return true.
	pattern = "abba", str = "dog cat cat fish" should return false.
	*/
	bool wordPattern(string pattern, string str) {
		istringstream in(str);
		for (int i = 0; i < pattern.size(); i++)
		{
			string word;
			if (!(in >> word)) return false;
			if ( mp.count(pattern[i]) && mp[pattern[i]] != word) return false;
			if (!mp.count(pattern[i]) && st.count(word)) return false;
			mp[pattern[i]] = word;
			st.insert(word);
		}
		string moreWord;
		if (in >> moreWord) return false;
		return true;
	}
private:
	map<char, string> mp;
	set<string> st;
}; 

int main()
{


	system("pause");
	return 0;
}

