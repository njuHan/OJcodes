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


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
	//morris traversal based method
	//非递归，无序栈，时间空间复杂度均为O(1);
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL) return NULL;

		TreeNode* pre=NULL, *cur = pRootOfTree;
		TreeNode* inorder = NULL, *ans = pRootOfTree;
		while (ans->left) ans = ans->left;
		while (cur)
		{
			if (cur->left == NULL)
			{
				//cout << cur->val;
				cur->left = inorder;
				if (inorder) inorder->right = cur;
				inorder = cur;
				cur = cur->right;
			}
			else
			{
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur) pre = pre->right;
				if (pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				else
				{
					//cout << cur->val;
                    //pre->right = NULL;
                    cur->left = inorder;
                    //这里可以不需要这一句，应为 inorder->right = cur 在之前就建立好了
                    //if (inorder) inorder->right = cur;
                    inorder = cur;
                    cur = cur->right;
				}
			}
		}
		return ans;
	}
	//递归，空间复杂度O(n),递归栈空间开销;
	TreeNode* Convert2(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL) return NULL;
		TreeNode* pre = NULL, *ans = pRootOfTree;
		while (ans->left) ans = ans->left;
		dfs(pRootOfTree, pre);
		return ans;
	}
private:
	void dfs(TreeNode* cur, TreeNode* &pre) //reference
	{
		if (cur == NULL) return;
		dfs(cur->left, pre);
		cur->left = pre;
		if (pre) pre->right = cur;
		pre = cur;
		dfs(cur->right, pre);
	}
};

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);

	node4->left = node2; node4->right = node6;
	node2->left = node1; node2->right = node3;
	node6->left = node5; node6->right = node7;
	Solution solu;
	TreeNode* ans =  solu.Convert(node4);

	system("pause");
	return 0;
}