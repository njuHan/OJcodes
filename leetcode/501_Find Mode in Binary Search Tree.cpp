#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
    vector<int> findMode(TreeNode* root) {
        TreeNode *pre = NULL, * cur = root;
        lastNode = NULL;
        maxcnt = curcnt = 0;
        while(cur)
        {
            if (cur->left==NULL)
            {
                pushAns(cur);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right && pre->right!=cur) pre = pre->right;
                if (pre->right == NULL) pre->right = cur, cur = cur->left;
                else pre->right = NULL, pushAns(cur), cur = cur->right;
            }
        }
        return ans;
    }
private:
    int maxcnt , curcnt;
    vector<int> ans;
    TreeNode* lastNode;
    void pushAns(TreeNode* cur)
    {
        //不能在结点改变的时候输出结果，否则会漏掉最后一个结点。
        //每遍历一个结点就考虑输出。
		if (lastNode && lastNode->val == cur->val) curcnt++;
        else curcnt = 1;
		if (curcnt>maxcnt) ans.clear(), ans.push_back(cur->val), maxcnt = curcnt;
		else if (curcnt == maxcnt) ans.push_back(cur->val);
        lastNode = cur;
    }     
};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		max = 0;
		inorder(root);
		vector<int> ans;
		for (auto e : valCnt)
		{
			if (e.second == max) ans.push_back(e.first);
		}
		return ans;
	}
private:
	int max;
	unordered_map<int, int> valCnt;
	void inorder(TreeNode* root)
	{
		if (root == NULL) return;
		inorder(root->left);
		valCnt[root->val]++;
		max = max < valCnt[root->val] ? valCnt[root->val] : max;
		inorder(root->right);
	}
};