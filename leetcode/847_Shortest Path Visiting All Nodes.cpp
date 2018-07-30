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
#include<numeric>
using namespace std;


struct State
{
	unsigned int cur_vis;
	int cost;
	State(unsigned int cv, int cost = 0) :cur_vis(cv), cost(cost) {}
};

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		queue<State> que;
		unordered_set<unsigned int> visited; //pruning
		int n = graph.size();
		unsigned int end = (1 << n) - 1;
		for (int i = 0; i < n; i++)
		{
			State temp((i << 16) | (1 << i), 0);
			visited.insert(temp.cur_vis);
			que.push(temp);
		}

		while (!que.empty())
		{
			State s = que.front(); que.pop();
			if ((s.cur_vis&end) == end) return s.cost;
			for (int j : graph[s.cur_vis >> 16])
			{
				//cout<<(s.cur_vis>>16)<<"-----------"<<endl;
				//cout<<(s.cur_vis>>16)<<", "<<(s.cur_vis&0x0000ffff)<<endl; 
				//cout<<j<<endl;
				unsigned int temp = s.cur_vis & 0x0000ffff;
				temp = temp | (j << 16) | (1 << j);
				//cout<<(temp>>16)<<", "<<(temp&0x0000ffff)<<endl; 
				if (!visited.count(temp))
				{
					que.push(State(temp, s.cost + 1));
					visited.insert(temp);
				}
			}
		}
		return -1;
	}
};