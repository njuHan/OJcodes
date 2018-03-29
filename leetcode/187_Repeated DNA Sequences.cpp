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
typedef multimap<string, int>::iterator mapit;
class Solution {
public:
	//不算重叠的子串
	vector<string> findRepeatedDnaSequences2(string s) 
	{
		int len = s.size();
		int repeatLen = 10;
		vector<string> ans;
		set<string> tempans;
		for (int i = 0; i + repeatLen <= len; i++)
		{
			string sub = s.substr(i, repeatLen);
			str2idx.insert(make_pair(sub, i));
			pair<mapit, mapit> range = str2idx.equal_range(sub);
			for (mapit j = range.first; j != range.second; j++)
			{
				if (abs(j->second - i) >= repeatLen)
				{
					tempans.insert(sub);
					break;
				}
			}
		}
		copy(tempans.begin(), tempans.end(), back_inserter(ans));
		return ans;
	}
	// 题目样例可以重叠子串
	vector<string> findRepeatedDnaSequences(string s)
	{
		int len = s.size();
		int repeatLen = 10;
		vector<string> ans;
		set<string> tempans;
		for (int i = 0; i + repeatLen <= len; i++)
		{
			string sub = s.substr(i, repeatLen);
			if (!st.count(sub)) st.insert(sub);
			else tempans.insert(sub);
		}
		copy(tempans.begin(), tempans.end(), back_inserter(ans));
		return ans;
	}
private:
	multimap<string, int> str2idx;
	set<string> st;
};
int main()
{


	system("pause");
	return 0;
}

