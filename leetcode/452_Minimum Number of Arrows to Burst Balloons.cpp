#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct cmp
{
	bool operator () (const pair<int,int>& a, const pair<int, int>& b) 
	{
		return a.first < b.first;
	}
};

class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0) return 0;
		sort(points.begin(), points.end(), cmp());
		int shoot = 1, shoot_begin = points[0].first, shoot_end = points[0].second;
		for (int i = 0; i < points.size(); i++)
		{
			if (shoot_end >= points[i].first)
			{
				shoot_begin = points[i].first;
				shoot_end = min(shoot_end, points[i].second);
			}
			else
			{
				shoot++;
				shoot_begin = points[i].first;
				shoot_end = points[i].second;
			}
		}
		return shoot;
	}
};

int main()
{
	vector<pair<int, int>> test = { {10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } };
	Solution solu; 
	int ans = solu.findMinArrowShots(test);
	cout << ans<<endl;
	system("pause");
	return 0;
}