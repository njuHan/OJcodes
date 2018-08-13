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
	string findLongestWord(string s, vector<string>& d) {
		string ans = "";
		for (string str : d)
		{
			int i, j;
			for (i = 0, j = 0; i < s.length() && j < str.length(); i++)
				j += (s[i] == str[j]);
			if (j == str.length() && (ans.length() < str.length() || (ans.length() == str.length() && ans > str)))
				ans = str;
		}
		return ans;
	}
};

class Solution2 {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (string& word : d)
        {
            int i=0, j=0;
            for ( ; i<s.length() && j<word.length(); i++ )
            {
                j += (s[i]==word[j]); 
            }                                         //字典序小的优先   
            if (j==word.length() && (ans.length()<j || (ans.length()==j && ans > word) )) ans = word;
        } 
        return ans;       
    }
};