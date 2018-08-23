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
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int ans = 0;
        while(!que.empty())
        {
            int m = que.size();
            while(m--)
            {
                TreeNode* node = que.front(); que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans++;
        }
        return ans;
    }
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		maxd = 0;
		getDepth(root, 1);
		return maxd;
	}
private:
	int maxd;
	void getDepth(TreeNode* node, int d)
	{
		if (!node) return;
		if (d > maxd) maxd = d; 
		getDepth(node->left, d + 1);
		getDepth(node->right, d + 1);
	}
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}