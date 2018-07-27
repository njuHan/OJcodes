/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return 1;
        dfs(root1);
        idx = 0;
        //for(int& e : leaf) cout<<e<<",";
        return dfsb(root2) && idx==leaf.size();
    }
private:
    vector<int> leaf;
    int idx;
    void dfs(TreeNode* node)
    {
        if (!node) return;
        if (node->left==NULL && node->right==NULL) leaf.push_back(node->val);
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }
    bool dfsb(TreeNode* node)
    {
        if (!node) return 1;
        if (node->left==NULL && node->right==NULL) return idx < leaf.size() && leaf[idx++]==node->val;
        return dfsb(node->left) && dfsb(node->right);
    }
};