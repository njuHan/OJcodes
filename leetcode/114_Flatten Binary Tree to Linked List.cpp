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

class Solution3 {
public:
	// 基于 morris traversal
    void flatten(TreeNode* root) {
        TreeNode* pre = NULL, * cur = root;
        while(cur)
        {
            if (cur->left == NULL)
                cur = cur->right;
            else
            {
                pre = cur->left;
                while(pre->right!=NULL && pre->right!=cur)
                    pre = pre->right;
                if (pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    //中序遍历到cur结点
					//cur 和 cur->right 之间插入一段链表；
					//该链表的第一个元素是cur->left,
					// 最后一个元素是pre, 即 中序遍历 cur 的上一个结点
                    pre->right = cur->right;
                    TreeNode* right = cur->right;
                    cur->right = cur->left;
                    cur->left = NULL;
                    cur = right;
                }
            }
        }
    }
};

class Solution2 {
public:
    // https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
	//右 左 根 遍历
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = next;
        root->left = NULL;
        next = root;
    }
private:
    TreeNode* next = NULL;
};


class Solution {
public:
	void flatten(TreeNode* root)
	{
		flatten(root, NULL);
	}
	TreeNode *flatten(TreeNode *root, TreeNode *tail) {
		//右 左 根 遍历， 和 上一个解法本质一样， tail 就是 next
		if (NULL == root) return tail;
		root->right = flatten(root->left, flatten(root->right, tail));
		root->left = NULL;
		return root;
	}

	void flatten2(TreeNode* root)
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