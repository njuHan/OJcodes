#include<iostream>
#include<cstdio>
#include<unordered_map>
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int len = nums.size();
		arr = nums;
		return cons(0, len);
		
	}
private:
	//[x,y)
	vector<int> arr;
	TreeNode* cons(int x, int y)
	{
		if (y - x < 1) return NULL;
		auto it = max_element(arr.begin() + x, arr.begin() + y);
		TreeNode* root = new TreeNode(*it);
		int p = it - arr.begin();
		root->left = cons(x, p);
		root->right = cons(p + 1, y);
		return root;
	}
};