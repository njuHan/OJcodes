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

// see: https://leetcode.com/problems/task-scheduler/discuss/104507/Python-Straightforward-with-Explanation

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> task2num;
		int m = 0; //最多出现次数
		for (char ch : tasks)
		{
			task2num[ch]++;
			m = max(task2num[ch], m);
		}
		int cntM = 0; //出现次数为m的task的数量
		for (auto data : task2num)
		{
			if (data.second == m)
				cntM++;
		}
		//贪心：出现次数最多的task,
		//最多出现次数 m, 放置m-1个需要 (m-1)*(n+1), 最后放第m个，（有m-1个具有冷却空闲的阶段）
		//其他出现次数等于m的task, 前m-1个插空，组后一个添加到队列尾
		//对于其他出现次数小于m的，每个阶段插空放置
		int ans = (m - 1)*(n + 1) + cntM;
		return max((int)tasks.size(), ans);
	}
};

int main()
{
	

	system("pause");
	return 0;
}



