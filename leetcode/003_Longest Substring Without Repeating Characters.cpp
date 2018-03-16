#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> chIdx;
		int i = -1, j = 0, maxlen = 0;
		while (j < s.size())
		{
			if (chIdx.count(s[j]))
				i = max(i, chIdx[s[j]]);
			maxlen = max(maxlen, j - i);
			chIdx[s[j]] = j;
			j++;
		}
		return maxlen;
	}
};

int main()
{
	Solution solu;
	int ans = solu.lengthOfLongestSubstring("");
	cout << ans << endl;
	system("pause");
	return 0;
}