#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool operator < (const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		size_t len = intervals.size();
		if (len < 1) return ans;
		sort(intervals.begin(), intervals.end());
		Interval cur = intervals[0];
		for (size_t i = 1; i < len; i++)
		{
			if (cur.end >= intervals[i].start)
			{
				cur.end = max(cur.end, intervals[i].end);
			}
			else
			{
				ans.push_back(cur);
				cur = intervals[i];
			}
		}
		ans.push_back(cur);
		return ans;
	}
};
int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}