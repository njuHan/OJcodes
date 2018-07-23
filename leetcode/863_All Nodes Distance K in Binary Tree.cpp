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
#include<numeric>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		getDist(root, target);
		dfs(root, dist[root], k);
		return ans;
	}
private:
	//store the distance between the node that is the ancestor of target node and the target node
	unordered_map<TreeNode*, int> dist; 
	vector<int> ans;
	int getDist(TreeNode* node, TreeNode* target)
	{
		if (node == NULL) return -1;
		if (node == target) return dist[node] = 0;
		int left = getDist(node->left, target);
		if (left != -1) return dist[node] = left + 1;
		int right = getDist(node->right, target);
		if (right != -1) return dist[node] = right + 1;
		return -1;
	}
	void dfs(TreeNode* node, int len, int k)
	{
		if (node == NULL) return;

		//if node is the ancestor of target node, 
		//we use the stored value in hashmap instead of the value (parameter len) from its parent node.
		if (dist.count(node)) len = dist[node];  
		if (len == k) ans.emplace_back(node->val);

		//if the distance from a node to target node is k, 
		//the distance from its child to the target node is k + 1,
		//unless the child node is closer to the target node which means the target node is in it's subtree.
		dfs(node->left, len + 1, k);
		dfs(node->right, len + 1, k);
	}
};