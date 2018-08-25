struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* insert(TreeNode* root, int val)
{
	if (root == NULL) return new TreeNode(val);
	if (root->val < val)  root->right = insert(root->right, val);
	else root->left = insert(root->left, val);
	return root;
}

TreeNode* insert2(TreeNode* root, int val)
{
	TreeNode* newnode = new TreeNode(val), *cur = root;
	while (cur)
	{
		if (cur->val < val)
		{
			if (cur->right) cur = cur->right;
			else { cur->right = newnode;  break; }
		}
		else
		{
			if (cur->left) cur = cur->left;
			else { cur->left = newnode; break; }
		}
	}
	return cur ? root : newnode;
}

// 返回val最小的结点
TreeNode* getMin(TreeNode* root)
{
	if (root == NULL) return root;
	if (root->left == NULL) return root;
	return getMin(root->left);
}

//删除val最小的结点
TreeNode* deleteMin(TreeNode* root)
{
	if (root == NULL) return NULL;
	if (root->left == NULL) return root->right;
	root->left = deleteMin(root->left);
	return root;
}

//删除结点
//1. 如果待删除的节点只有一个子树，那么只需要让指向待删除节点的链接指向唯一的子树即可；
//2. 否则，让右子树的最小节点替换该节点。 这里用到 getMin deleteMin
TreeNode* deleteNode(TreeNode* root, int val)
{
	if (root == NULL) return NULL;
	if (root->val < val) return deleteNode(root->right, val);
	else if (root->val > val) return deleteNode(root->left, val);

	if (root->left == NULL) root = root->right;
	else if (root->right == NULL) root = root->left;
	else
	{
		TreeNode* temp = root;
		root = getMin(root->right);
		root->right = deleteMin(root->right);
		root->left = temp->left;
	}
}