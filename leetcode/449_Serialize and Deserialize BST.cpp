#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>

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
		if (root == NULL) return "";
		char buff[4];
		string mid;
		memcpy(buff, &root->val, sizeof(buff));
		mid.append(buff, sizeof(buff));
		return mid + this->serialize(root->left) + this->serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int len = data.size() / 4; 
		if (len < 1) return NULL;
		const int* pos = (const int*)data.c_str();
		int rootVal = pos[0];
		TreeNode* root = new TreeNode(rootVal);
		int i = 1;
		while (i < len && pos[i] < rootVal) i++; //find the root of right subtree
		if (i < len) root->right = deserialize(string(&data[i * 4], &data[len * 4])); //right
		if (1 < i) root->left = deserialize(string(&data[4], &data[i * 4])); //left
		return root;
	}

};

int main()
{
	char buff[4];
	string str;
	for (int i = 0; i < 4; i++)
	{
		memcpy(buff, &i, 4);
		str.append(buff, sizeof(buff));
	}
	const char* temp = str.c_str();
	const int* p = (const int*)temp;
	for (int i = 0; i < 4; i++)
		cout << p[i] << " ";
	cout << str.size();

	system("pause");
	return 0;
}

