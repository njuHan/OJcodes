#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
#include<algorithm>
using namespace std;


// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	Node* construct(vector<vector<int>>& grid) {
		int n = grid.size();
		return cons(0, 0, n, grid);
	}
private:
	Node* cons(int x, int y, int len, vector<vector<int>>& grid)
	{
		if (len == 0) return NULL;
		if (len == 1)	return new Node(grid[x][y], 1, 0, 0, 0, 0);
		int len2 = len >> 1;
		Node* tl = cons(x, y, len2, grid), *tr = cons(x, y + len2, len2, grid);
		Node* bl = cons(x + len2, y, len2, grid), *br = cons(x + len2, y + len2, len2, grid);
		Node* root = NULL;
		//为叶节点 && 四个叶节点val相等
		if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
		{
			root = new Node(tl->val, 1, 0, 0, 0, 0);
			delete tl, delete tr, delete bl, delete br;
		}
		else
			root = new Node(1, 0, tl, tr, bl, br);
		return root;
	}
};
