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

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;
	stack<TreeNode*> sk;
	TreeNode* curNode = root, *lastNode = NULL;
	while (curNode || !sk.empty())
	{
		if (curNode)
		{
			sk.push(curNode);
			curNode = curNode->left;
		}
		else
		{
			TreeNode* node = sk.top();
			if (node->right && node->right != lastNode)
			{
				curNode = node->right;
			}
			else
			{
				ans.push_back(node->val);
				lastNode = node;
				sk.pop();
			}
		}
	}
	return ans;
}

//内循环 while 一直向左走
//前序， 中序， 后序 框架类似
vector<int> postorderTraversal2(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;
	stack<TreeNode*> sk;
	TreeNode* curNode = root, *lastNode = NULL;
	while (curNode || !sk.empty())
	{
		while (curNode)
		{
			sk.push(curNode);
			curNode = curNode->left;
		}

		TreeNode* node = sk.top();
		if (node->right && node->right != lastNode)
		{
			curNode = node->right;
		}
		else
		{
			ans.push_back(node->val);
			lastNode = node;
			sk.pop();
		}


	}
	return ans;
}
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sk;
        while(root || !sk.empty())
        {
            while(root) 
            {
                sk.push(root);
                ans.emplace_back(root->val);
                root = root->left;
            }
            TreeNode* node = sk.top(); sk.pop();
            root = node->right;
        }
        return ans;
    }
	
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sk;
        while(root || !sk.empty())
        {
            while(root) 
            {
                sk.push(root);
                root = root->left;
            }
            TreeNode* node = sk.top(); sk.pop();
            ans.emplace_back(node->val);
            root = node->right;
        }
        return ans;
    }
	
	