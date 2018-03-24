#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		this->sum = sum;
		if (!root) return ans;
		vector<int> vec;
		search(vec, 0, root);
		return ans;
	}
private:
	vector<vector<int>> ans;
	int sum;
	void search(vector<int> vec, int curSum, TreeNode* node)
	{
		curSum += node->val;
		//if (curSum > sum) return; 有负数结点。。。。
		vec.push_back(node->val);
		if (!node->left && !node->right && curSum == sum)
		{
			ans.push_back(vec);
			return;
		}
		if (node->left)
			search(vec, curSum, node->left);
		if (node->right)
			search(vec, curSum, node->right);
			
	}
};

int main()
{
	Solution solu;
	TreeNode node1(-2);
	TreeNode node2(2);
	TreeNode node3(-3);
	
	node1.right = &node3;
	vector<vector<int>>ans = solu.pathSum(&node1,-5);
	system("pause");
	return 0;
}