class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size()) return NULL;
		this->pre = pre, this->in = vin;
		return build(0, pre.size()-1, 0, in.size()-1);
	}
private:
	vector<int> pre, in;
	TreeNode* build(int p, int q, int x, int y)
	{
        if (q < p || y < x) return NULL;
		TreeNode* root = new TreeNode(pre[p]);
		int mid = x;
		while (in[mid] != pre[p]) mid++;
		int leftLen = mid - x;
		root->left = build(p + 1, p + leftLen, x, mid - 1);
		root->right = build(p + leftLen + 1, q, mid + 1, y);
		return root;
	}
};