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
        // 按结束时间排序， 优先考虑早结束的课程，课程长度小的课程
        sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1.back() < v2.back() || (v1.back() == v2.back() && v1[0] < v2[0]); });
		priority_queue<int> que; //max heap，存储课程时间长度，长度最长的课在堆顶
		int curEnd = 0;
		for(vector<int> cos : courses)
		{
			if (curEnd + cos[0] <= cos[1]) // 有空间可以直接添加
			{
				curEnd += cos[0];
				que.push(cos[0]);
			}
			else if (!que.empty() && que.top() > cos[0]) //替换堆定时间较长的课程，
			{
				curEnd = curEnd - que.top() + cos[0]; // 因为按照结束时间排序，肯定满足：curEnd = curEnd - que.top() + cos[0] <= cos[1] 
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



