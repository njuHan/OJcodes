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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size());
		
	}
	TreeNode* build(vector<int>& nums, int x, int y)
	{
		if (y - x < 1) return NULL;
		int m = x + (y - x) / 2;
		TreeNode* root = new TreeNode(nums[m]);
		root->left = build(nums, x, m);
		root->right = build(nums, m + 1, y);
		return root;
	}
};

int main()
{
	
	system("pause");
	return 0;
}

