#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return{ 0 };
		vector<int> cur, next;
		unordered_map<int, unordered_set<int>> adj;
		for (auto p : edges)
		{
			adj[p.first].insert(p.second);
			adj[p.second].insert(p.first);
		}
		for (int i = 0; i < n; i++)
			if (adj[i].size() == 1) cur.push_back(i);
		while (!cur.empty())
		{
			next.clear();
			for (int v : cur)
				for (int u : adj[v])
				{
					adj[u].erase(v);
					if (adj[u].size() == 1) next.push_back(u);
				}
			swap(next, cur);
		}
		return next;
	}
};