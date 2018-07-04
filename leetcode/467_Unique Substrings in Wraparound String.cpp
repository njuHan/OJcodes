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
#include<ctime>
#include<numeric>

using namespace std;
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> dp(26, 0); //以字母i结尾的所有不重复子串个数
		int len = 0;
		for (int i=0; i<p.length(); i++)
		{
			if (i > 0 && (p[i] - p[i - 1] + 26) % 26 != 1) len = 0;
			int idx = p[i] - 'a';
			dp[idx] = max(dp[idx], ++len);
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};