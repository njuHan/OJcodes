#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL) return 0;
		//在pathSum函数中考虑是否从当前结点出发
		//这样避免了结点重复起始
		return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		
	}
private:
	//dfs只考虑累加探索
	int dfs(TreeNode* node, int sum)
	{
		if (node == NULL) return 0;
		sum -= node->val;
		return (sum==0) + dfs(node->left, sum) + dfs(node->right, sum);
	}

	/*
	for each parent node in the tree, we have 2 choices:
	1. include it in the path to reach sum.
	2. not include it in the path to reach sum.

	for each child node in the tree, we have 2 choices:
	1. take what your parent left you.
	2. start from yourself to form the path.

	one little thing to be careful:
	every node in the tree can only try to be the start point once.

	for example, When we try to start with node 1, node 3, as a child, could choose to start by itself.
	Later when we try to start with 2, node 3, still as a child,
	could choose to start by itself again, but we don't want to add the count to result again.
	1
	 \
	   2
		 \
		   3

	*/
	/* 重复访问的错误示范：
	void dfs(int cursum, TreeNode* next, vector<int> vec)
	{
		if (cursum == target)
		{
			cnt++;
			for (int e : vec)
				cout << e << ",";
			cout << endl;
		}
		if (next == NULL) return;
		vec.push_back(next->val);
		dfs(cursum + next->val, next->left,vec);
		dfs(cursum + next->val, next->right, vec);
		vector<int> newvec;
		dfs(0, next->left, newvec);
		dfs(0, next->right, newvec);

	}
	*/
};

int main()
{
	
	return 0;
}