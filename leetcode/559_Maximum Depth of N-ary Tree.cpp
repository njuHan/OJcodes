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
    int maxDepth(Node* root) {
        if (root==NULL) return 0;
        int maxh = 0;
        for (auto& node : root->children)
        {
            maxh = max(maxh, maxDepth(node));
        }
        return maxh+1;
    }
};