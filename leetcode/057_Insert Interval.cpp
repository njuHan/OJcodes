#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto cmp = [](const Interval& intv1, const Interval& intv2) {return intv1.end < intv2.start; };
		vector<Interval> ans(intervals.begin(), intervals.end());
		auto range = equal_range(ans.begin(), ans.end(), newInterval, cmp);
		auto it1 = range.first, it2 = range.second;
		/*
		for (auto i = it1; i != it2; i++)
		{
			cout << i->start << "," << i->end << endl;
		}
		*/
		if (it1 == it2) ans.insert(it1, newInterval);
		else
		{
			it2--;
			it2->start = min(newInterval.start, it1->start);
			it2->end = max(newInterval.end, it2->end);
			ans.erase(it1, it2);
		}
		return ans;
	}
};