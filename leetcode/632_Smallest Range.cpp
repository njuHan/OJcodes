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


// https://leetcode.com/problems/smallest-range/discuss/104886/Clean-C++-priority_queue-solution-using-iterators
typedef vector<int>::iterator VecIt;
typedef pair<VecIt, VecIt> Node; //first: cur pointer, second: end pointer
struct comp
{
	bool operator () (const Node& lhs, const Node& rhs)
	{
		return *lhs.first > *rhs.first;
	}
};
class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		priority_queue<Node, vector<Node>, comp> que;
		int lo = INT_MAX, hi = INT_MIN; 
		for (auto &row : nums) // attention! use reference
		{
			lo = min(lo, row[0]);
			hi = max(hi, row[0]);
			//push each row's first element's pointer, 
			//and the row's end pointer, since we need to konw the row's end, while doing iterator++;
			que.push({ row.begin(), row.end() });
		}
		vector<int> ans{ lo, hi };
		while (true)
		{
			Node minNode = que.top(); que.pop();
			if (++minNode.first == minNode.second) break; // reach the end;
			que.push(minNode);
			lo = *que.top().first;
			hi = max(hi, *minNode.first);
			if (hi - lo < ans[1] - ans[0])
				ans = { lo, hi };
		}
		return ans;
	}
};