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
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		// handle multi parent
		int p1,  p2 = -1; // redundant parent
		int son = 0;
		for (auto& e : edges) // e[0] -> e[1]
		{
			p1 = findpa(e[1]);
			if (p1 != e[1] && p1 != e[0]) //
			{
				p2 = e[0];
				son = e[1];
				e[0] = e[1] = -1; //try delete
			}
			else
				pa[e[1]] = e[0];
		}
		for (auto& e : edges)
		{
			if (e[0] == -1 && e[1] == -1)
			{
				e[0] = p2;
				e[1] = son;
				continue;
			}
			int x = findst(e[0]), y = findst(e[1]);
			if (x == y)
			{
				if (p2 != -1)
					return{ pa[son], son };
				else
					return e;

			}
			else
				st[y] = x;
		}
		return { p2,son };
	}
private:
	unordered_map<int, int> pa;
	unordered_map<int, int> st;
	int findpa(int x)
	{
		if (pa.count(x) == 0)
			return pa[x] = x;
		else
			return pa[x];
	}
	int findst(int x)
	{
		if (st.count(x) == 0)
			return st[x] = x;
		else
			return st[x] == x ? x : st[x] = findst(st[x]);
	}
};