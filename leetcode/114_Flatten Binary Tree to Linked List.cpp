#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void flatten(TreeNode* root)
	{
		TreeNode* p = root;
		TreeNode* q;
		while (p)
		{
			curR = p;
			q = p->right;
			if (p->left)
			{
				insert(p->left);
				p->left = NULL;
			}
			p = q;
		}
	}
private:
	TreeNode* curR;

	// 按照 右 左 根的顺序依次插入链表第二个
	void insert(TreeNode* node)
	{
		if (node->right)
			insert(node->right);

		if (node->left)
			insert(node->left);
		
		node->left = NULL;
		TreeNode* next = curR->right;
		curR->right = node;
		node->right = next;

		
	}
};

int main()
{
	Solution solu;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	solu.flatten(&n1);
	system("pause");
	return 0;
}