#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

// https://leetcode.com/problems/max-points-on-a-line/discuss/47124/16ms28ms-C++-Solutions-with-Explanations
	
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
	  
class Solution {
public:
	int maxPoints2(vector<Point>& points) {
		int n = points.size();
		if (n <= 2) return n;
		map<pair<int,int>, int> mapk;
		int duplicate, maxp = 0;
		for (int i = 0; i < n; i++)
		{
			mapk.clear();
			duplicate = 1;
			int x1 = points[i].x, y1 = points[i].y;
			for (int j = i + 1; j < n; j++)
			{
				int x2 = points[j].x, y2 = points[j].y;
				if (x1 == x2 && y1 == y2) { duplicate++;  continue; }
				int dx = x2 - x1, dy = y2 - y1;
				int divide = gcd(dx, dy);
				mapk[make_pair(dy / divide, dx / divide)]++;
			}
			maxp = max(duplicate, maxp);
			for (auto e : mapk)
				maxp = max(maxp, duplicate + e.second);
		}
		return maxp;
	}
private:
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a%b);
	}

	// 斜率double, 精度问题
	int maxPoints2(vector<Point>& points) {
		int n = points.size();
		if (n <= 2) return n;
		unordered_map<double, int> mapk;
		int duplicate, maxp = 0;
		for (int i = 0; i < n; i++)
		{
			mapk.clear();
			duplicate = 1;
			int x1 = points[i].x, y1 = points[i].y;
			for (int j = i + 1; j < n; j++)
			{
				int x2 = points[j].x, y2 = points[j].y;
				if (x1 == x2 && y1 == y2) duplicate++;
				else if (x1 == x2) mapk[INT_MAX]++;
				else mapk[(double)(y2 - y1) / (double)(x2 - x1)]++;
			}
			maxp = max(duplicate, maxp);
			for (auto e : mapk)
				maxp = max(maxp, duplicate + e.second);
		}
		return maxp;
	}
};