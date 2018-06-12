#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == NULL) return NULL;
		ostringstream out;
		ser(root, out);
		char* p = new char[out.str().length() + 1];
		strcpy(p, out.str().c_str());
		return p;
	}
	TreeNode* Deserialize(char *str) {
		if (str == NULL || strlen(str)==0) return NULL;
		istringstream in(str);
		return des(in);
	}
private:
	void ser(TreeNode* node, ostringstream& out)
	{
		if (node)
		{
			out << node->val << " ";
			ser(node->left, out);
			ser(node->right, out);
		}
		else
			out << "# ";
	}
	TreeNode* des(istringstream& in)
	{
		string temp;
		in >> temp;
		if (temp == "#") return NULL;
		TreeNode* node = new TreeNode(stoi(temp));
		node->left = des(in);
		node->right = des(in);
		return node;
	}
};