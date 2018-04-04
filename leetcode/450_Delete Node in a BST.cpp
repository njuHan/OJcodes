#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL) return NULL;
		if (root->val == key)
		{
			if (root->right == NULL)
			{
				TreeNode* left = root->left;
				delete root;
				return left;
			}
			else //找到右子树最小的结点，也是中序遍历的下一个结点
			{
				TreeNode* next = root->right;
				while (next->left != NULL) next = next->left;
				swap(next->val, root->val);
				root->right = deleteNode(root->right, key);
				return root;
			}
			
		}
		if (key < root->val)
			root->left = deleteNode(root->left, key);
		else
			root->right = deleteNode(root->right, key);
		return root;
	}
private:
	
};

int main()
{

	system("pause");
	return 0;
}

