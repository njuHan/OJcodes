//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C++JavaPython-One-Pass-Real-O(N)
class Solution2 {
public:
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        if (pre.empty()) return NULL;
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i=1, j=0; i<pre.size(); i++)
        {
            while (s.back()->val == post[j]) s.pop_back(), j++;
            TreeNode* node = new TreeNode(pre[i]);
            if (s.back()->left) s.back()->right = node;
            else s.back()->left = node;
            s.push_back(node);
        }
        return s[0];
    }
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return NULL;
        int n = post.size();
        for (int i=0; i<n; i++) num2idx[post[i]] = i;
        return build(pre, post, 0,n, 0, n);
    }
private:
    unordered_map<int, int> num2idx;
    //[a, b)
    TreeNode* build(vector<int>& pre, vector<int>& post, int a, int b, int c, int d)
    {
        if (a>=b) return NULL;
        TreeNode* root = new TreeNode(pre[a]);
        if (b-a==1) return root;
        int idx = num2idx[pre[a+1]];
        int len = idx - c + 1;
        root->left = build(pre, post, a+1, a+1+len, c, idx+1);
        root->right = build(pre, post, a+1+len, b, idx+1, d-1);
        return root;
    }
};