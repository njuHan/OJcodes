
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre, *cur = root, *ans = root,  *last = NULL;
        while(ans && ans->left) ans = ans->left;
        while(cur)
        {
            if (cur->left)
            {
                pre = cur->left;
                while(pre->right && pre->right!=cur) pre = pre->right;
                if (pre->right==NULL) pre->right = cur, cur = cur->left;
                else
                {
                    cur->left = NULL;
                    if (last) last = last ->right = cur;
                    else last = cur;
                    cur = cur->right;
                }
            }
            else
            {
                if (last) last = last ->right = cur;
                else last = cur;
                cur = cur->right;
            }
        }
        return ans;
    }
};
