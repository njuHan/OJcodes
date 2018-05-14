#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		for (auto e : edges)
		{
			int x = find(e[0]), y = find(e[1]);
			if (x == y)
				return { e[0], e[1] };
			else
				pa[x] = y;
		}
	}
private:
	unordered_map<int, int> pa;
	int find(int x)
	{
		if (pa.count(x) == 0) 
			return pa[x] = x;
		else
			return pa[x] == x ? x : pa[x] = find(pa[x]);
	}
};