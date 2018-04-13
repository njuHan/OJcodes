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



