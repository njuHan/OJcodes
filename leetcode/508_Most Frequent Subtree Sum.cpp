#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int x = []()
{     
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> ans;
		if (!root) return ans;
		max = 0;
		getSum(root);
		for (auto e : valCnt)
		{
			if (e.second == max)
				ans.push_back(e.first);
		}
		return ans;
	}
private:
	unordered_map<int, int> valCnt;
	int max;
	int getSum(TreeNode* node)
	{
		if (node == NULL) return 0;
		int left = getSum(node->left);
		int right = getSum(node->right);
		int val = node->val + left + right;
		valCnt[val]++;
		max = max < valCnt[val] ? valCnt[val] : max;
		return val;
	}
};