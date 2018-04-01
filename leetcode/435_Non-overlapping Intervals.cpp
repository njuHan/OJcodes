#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		int len = intervals.size();
		if (len < 1) return 0;
		int ans = 0;
		sort(intervals.begin(), intervals.end(), [](const Interval& int1, const Interval& int2) { return int1.end < int2.end; });
		int end = intervals[0].end;
		for (int i = 1; i < len; i++)
		{
			if (intervals[i].start < end)
				ans++;
			else
				end = intervals[i].end;
		}
		return ans;
	}
};

int main() {



	system("pause");
	return 0;
}
