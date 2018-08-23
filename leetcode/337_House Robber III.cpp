#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3 {
public:
    //间隔遍历
    int rob(TreeNode* root) {
        if (root==NULL) return 0;
        int take = root->val;
        if (root->left) take += rob(root->left->left) + rob(root->left->right);
        if (root->right) take += rob(root->right->left) + rob(root->right->right);
        
        int nontake = rob(root->left) + rob(root->right);
        return max(take, nontake);
    }
};

class Solution2 {
public:
    int rob(TreeNode* root) {
        int take, nontake;
        return search(root, take, nontake);
    }
private:
    // 参数使用引用是为了方便传多个参数
    // take: 拿该结点； nontake: 不拿该结点
    int search(TreeNode* node, int& take, int& nontake)
    {
        if (!node) { take = nontake = 0; return 0; } //take nontake省略参数初始化， 所以在函数内必须赋值
        int l1 , l2 , r1 , r2 ;
        int left = search(node->left, l1, l2), right = search(node->right, r1, r2);
        take = node->val + l2 + r2;
        nontake = left + right;
        return max(take, nontake);
    }
};

class Solution {
public:
	int rob(TreeNode* root) {
		int take, nottake;
		return search(root, take, nottake);
	}
	int search(TreeNode* node, int& take, int& nottake)
	{
		if (node == NULL) return 0;
		int ltake = 0, lnot = 0, rtake = 0, rnot = 0;
		int lmax = search(node->left, ltake, lnot);
		int rmax = search(node->right, rtake, rnot);
		nottake = lmax + rmax;
		take = node->val + lnot + rnot;
		return max(take, nottake);
	}
};

int main()
{

	system("pause");
	return 0;
}



