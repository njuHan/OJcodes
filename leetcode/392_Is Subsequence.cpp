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
	bool isSubsequence(string s, string t) {
		vector<vector<int>> chIdx(26);
		for (int i = 0; i < t.size(); i++)
			chIdx[t[i] - 'a'].emplace_back(i);
		int idx = -1;
		for (int i = 0; i < s.size(); i++)
		{
			int temp = s[i] - 'a';
			auto it = upper_bound(chIdx[temp].begin(), chIdx[temp].end(), idx);
			if (it == chIdx[temp].end()) return false;
			else idx = *it;
		}
		return true;
	}

	
};

int main()
{


	system("pause");
	return 0;
}

