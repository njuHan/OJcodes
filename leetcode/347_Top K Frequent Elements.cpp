#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;



struct cmp
{
	bool operator () (const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.second>p2.second;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> numCnt;
		for (int e : nums) numCnt[e]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;

		for (auto e : numCnt)
		{
			if (que.size() < k)
				que.push(make_pair(e.first, e.second));
			else
			{
				if (que.top().second < e.second)
				{
					que.pop();
					que.push(make_pair(e.first, e.second));
				}
			}
		}
		vector<int> ans;
		while (!que.empty())
		{
			ans.emplace_back(que.top().first);
			que.pop();
		}
		return ans;
	}

};

int main()
{
	vector<int> vec = { 5,2,5,3,5,3,1,1,3 };
	Solution solu;
	solu.topKFrequent(vec, 2);
	return 0;
}