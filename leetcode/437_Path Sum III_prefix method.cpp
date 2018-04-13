#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;

//https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method?page=3

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		preSum.emplace(0, 1);
		return dfs(root, 0, sum);

	}
private:
	unordered_map<int, int> preSum;
	//记录从根结点到当前结点的所有前缀和，eg : A->B->C  sum(A,B), sum(A,B,C)
	int dfs(TreeNode* node, int sum, int target)
	{
		if (node == NULL) return 0;
		sum += node->val;
		int ans = 0;
		//target == 从根结点到当前结点的和 - 从根结点到中间结点的和 
		//即： 从中间结点到当前结点的和 == target
		if (preSum.count(sum - target)) 
			ans += preSum[sum - target];
		preSum[sum]++;
		ans += dfs(node->left, sum, target) + dfs(node->right, sum, target);
		preSum[sum]--; //本结点递归结束，返回父节点
		return ans;
	}

};

int main()
{

	return 0;
}