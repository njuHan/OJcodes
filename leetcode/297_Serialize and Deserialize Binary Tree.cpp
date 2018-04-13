#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
	}
private:
	void serialize(TreeNode* node, ostringstream& out)
	{
		if (node)
		{
			out << node->val<<' ';
			serialize(node->left, out);
			serialize(node->right, out);
		}
		else
			out << "# ";
	}
	TreeNode* deserialize(istringstream& in)
	{
		string val;
		in >> val;
		if (val == "#") return NULL;
		TreeNode* node = new TreeNode(stoi(val));
		node->left = deserialize(in);
		node->right = deserialize(in);
		return node;
	}
};

int main()
{
	int delim = -1;
	string str;
	str.append((char*)&delim, sizeof(int));
	int* p = (int*)str.c_str();
	cout << *p;
	system("pause");
	return 0;
}



