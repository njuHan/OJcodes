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
#include<functional>
using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.first<rhs.first || (lhs.first == rhs.first&&lhs.second>rhs.second); });
		vector<int> lis; //longest increasing sequence
		for (auto e : envelopes)
		{
			int pos = lower_bound(lis.begin(), lis.end(), e.second) - lis.begin();
			if (pos == lis.size()) lis.push_back(e.second);
			else lis[pos] = e.second;
		}
		return lis.size();
	}
};