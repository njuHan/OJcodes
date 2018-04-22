#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void inorderMorrisTraversal(TreeNode *root)
{
	TreeNode* pre = NULL, *cur = root;
	while (cur)
	{
		if (cur->left == NULL) //输出左结点
		{
			cout << cur->val;
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right!=NULL && pre->right!=cur)
			{
				pre = pre->right;
			}
			if (pre->right == NULL) //建立返回指针
			{
				pre->right = cur;
				cur = cur->left; //继续建立左子树返回指针
			}
			else //if (pre->right == cur) //输出根结点， 消除返回指针
			{  //已经遍历完左子树
				pre->right = NULL;
				cout << cur->val;  //输出根结点
				cur = cur->right; //考虑右子树
			}
		}
	}
}
//前序遍历
void preorderMorrisTraversal(TreeNode *root)
{
	TreeNode* pre = NULL, *cur = root;
	while (cur)
	{
		if (cur->left == NULL)
		{
			cout << cur->val;
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right!=NULL && pre->right!=cur)
			{
				pre = pre->right;
			}
			if (pre->right == NULL)
			{
				cout << cur; //先序，在建立返回指针时， 先输出根结点
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				cur = cur->right;
			}

		}
	}
}

//后序遍历，操作比较复杂
void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
{
	if (from == to)
		return;
	TreeNode *x = from, *y = from->right, *z;
	while (true)
	{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if (x == to)
			break;
	}
}

void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
{
	reverse(from, to);

	TreeNode *p = to;
	while (true)
	{
		printf("%d ", p->val);
		if (p == from)
			break;
		p = p->right;
	}

	reverse(to, from);
}

void postorderMorrisTraversal(TreeNode *root) {
	TreeNode dump(0);
	dump.left = root;
	TreeNode *cur = &dump, *prev = NULL;
	while (cur)
	{
		if (cur->left == NULL)
		{
			cur = cur->right;
		}
		else
		{
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL)
			{
				prev->right = cur;
				cur = cur->left;
			}
			else
			{
				printReverse(cur->left, prev);  // call print
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
}

//用栈实现后序遍历
void postorderTraversal(TreeNode* root)
{
	if (root==NULL) return;
	stack<TreeNode*> sk;
	sk.push(root);
	TreeNode* pre=NULL, cur = NULL;
	while(!sk.empty())
	{
		cur = sk.top();
		//如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，  
            //则直接输出该节点，将其出栈，将其设为上一个访问的节点  
		if ((cur->left==NULL && cur->right==NULL)||(pre!=NULL && (cur->left==pre || cur->right==pre)))
		{
			cout<<cur->val;
			sk.pop();
			pre = cur;
		}
		else
		{
			if (cur->left)
				sk.push(cur->left);
			if (cur->right)
				sk.push(cur->right);
		}
			
	}
	
}
	
	