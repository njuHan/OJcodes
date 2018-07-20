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


// Definition for a Node.
class Node {
public:
	int val = NULL;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		queue<Node*> que;
		que.push(root);
		while (!que.empty())
		{
			int m = que.size();
			vector<int> level;
			while (m--)
			{
				Node* node = que.front(); que.pop();
				level.emplace_back(node->val);
				for (auto e : node->children)
					if (e != NULL) que.push(e);
			}
			ans.emplace_back(level);
		}
		return ans;
	}
};