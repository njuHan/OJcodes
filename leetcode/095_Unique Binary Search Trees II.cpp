#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
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
	TreeNode* cloneTree(TreeNode* root)
	{
		if (!root) return root;
		TreeNode* newRoot = new TreeNode(root->val);
		newRoot->left = cloneTree(root->left);
		newRoot->right = cloneTree(root->right);
		return newRoot;
	}
	void deleteTree(TreeNode* root)
	{
		if (!root) return;
		delete root->left;
		delete root->right;
		delete root;
	}
	vector<TreeNode*> generateTrees(int n) 
	{
		if (n <= 0) return result;
		TreeNode* root = new TreeNode(1);
		result.push_back(root);
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < result.size(); j++)
			{
				TreeNode* oldRoot = result[j];
				TreeNode* newNode = new TreeNode(i);
				TreeNode* cur = cloneTree(oldRoot);
				// add as root
				newNode->left = cur;
				tempRes.push_back(newNode);

				// find all right node
				TreeNode* pre = oldRoot;
				TreeNode* rightNode = oldRoot->right;
				while (rightNode)
				{
					TreeNode* newNode = new TreeNode(i);
					pre->right = newNode;
					newNode->left = rightNode;
					//clone the modified old tree
					TreeNode* curRoot = cloneTree(oldRoot);
					tempRes.push_back(curRoot);
		            // recover the old tree
					pre->right = rightNode;
					//go next right node
					pre = pre->right;
					rightNode = rightNode->right;
				}
				// replace the right NULL at the old tree
				// don't have to clone a new tree
				pre->right = new TreeNode(i);
				tempRes.push_back(oldRoot);

			}
			swap(result, tempRes);
			tempRes.clear();

		}
		return result;
	}
	
private:
	vector<TreeNode*> tempRes;
	vector<TreeNode*> result;
};

int main()
{
	Solution solu;

	vector<TreeNode*> vec = solu.generateTrees(3);
	//printf("%d\n", ans);
	system("pause");
	return 0;
}