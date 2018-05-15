#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
class Solution {
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		if (N <= 0) return ans;
		n = N;
		count = vector<int>(n, 0);
		ans = vector<int>(n, 0);
		tree = vector<unordered_set<int>>(n);
		for (auto e : edges) // 构造每个结点为根结点的子树结点集合
		{
			tree[e[0]].insert(e[1]);
			tree[e[1]].insert(e[0]);
		}
		int root = 0; //以结点 0 为树根，建立信息
		vis.clear();
		postDfs(root);
		vis.clear();
		preDfs(root);
		return ans;
	}
private:
	int n; //结点个数
	vector<int> count; //count[i] 以i为根结点的子树结点个数
	vector<int> ans;
	unordered_set<int> vis; 
	vector<unordered_set<int>> tree;
	void postDfs(int root) //从下到上，记录每个子树的结点个数count[i]，此时ans[i]表示子树i的根结点i到自己子树结点的距离和
	{
		vis.insert(root);
		for (int i : tree[root])
		{
			if (!vis.count(i))
			{
				postDfs(i);
				count[root] += count[i];
				ans[root] += count[i] + ans[i];
			}
		}
		count[root]++; //add root
	}
	void preDfs(int root)
	{
		vis.insert(root);
		for (int i : tree[root])
		{
			if (!vis.count(i))
			{
				ans[i] = ans[root] - count[i] + (n - count[i]);
				preDfs(i);
			}
		}
	}
};