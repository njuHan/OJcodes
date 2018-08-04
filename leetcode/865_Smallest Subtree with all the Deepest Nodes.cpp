#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
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
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (!root) return NULL;
		int l = depth(root->left), r = depth(root->right);
		return l == r ? root : (l > r ? subtreeWithAllDeepest(root->left) : subtreeWithAllDeepest(root->right));
	}
private:
	int depth(TreeNode* node)
	{
		if (!node) return 0;
		return max(depth(node->left), depth(node->right)) + 1;
	}
};
class Solution2 {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		return depth(root).second;
	}
private:
	pair<int, TreeNode*> depth(TreeNode* node)
	{
		if (!node) return{ 0, NULL };
		pair<int, TreeNode*> left = depth(node->left), right = depth(node->right);
		return{ max(left.first, right.first) + 1, left.first == right.first ? node : (left > right ? left.second : right.second) };
	}
};