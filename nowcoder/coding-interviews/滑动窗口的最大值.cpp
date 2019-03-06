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
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		int len = num.size(), k = size;
		vector<int> ans;
		if (len < 1 || size < 1) return ans;
		deque<int> dq;
		for (int i = 0; i < len; i++)
		{
			while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
			while (!dq.empty() && num[dq.back()] < num[i]) dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.emplace_back(num[dq.front()]);
		}
		return ans;
	}
};
