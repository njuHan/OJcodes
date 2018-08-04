/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> sk;
        sk.push(root);
        while(!sk.empty())
        {
            Node* node = sk.top(); sk.pop();
            if (!node) continue;
            ans.emplace_back(node->val);
            for (int i = node->children.size()-1; i>=0; i--) sk.push(node->children[i]);
        }
        return ans;
    }
};