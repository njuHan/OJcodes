#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

// see: https://leetcode.com/problems/course-schedule-iii/discuss/104840/C++-13-lines-With-Explanation

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1.back() < v2.back() || (v1.back() == v2.back() && v1[0] < v2[0]); });
		priority_queue<int> que; //max heap
		int curEnd = 0;
		for(vector<int> cos : courses)
		{
			if (cos[0] > cos[1]) continue;
			if (curEnd + cos[0] <= cos[1])
			{
				curEnd += cos[0];
				que.push(cos[0]);
			}
			else if (!que.empty() && que.top() > cos[0]) //替换一个比它时间长并且结束时间更早的课
			{
				curEnd = curEnd - que.top() + cos[0];
				que.pop();
				que.push(cos[0]);
			}
		}

		return que.size();
	}
};

int main()
{
	

	
	system("pause");
	return 0;
}



