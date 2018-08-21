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
using namespace std;


struct T
{
	int x, y, t;
	T(int _x = 0, int _y = 0, int _t = 0):x(_x), y(_y), t(_t){}
	bool operator < (const T& rhs) const { return this->t > rhs.t; } //const 必须有
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (matrix.empty()) return 0;
		int n = matrix.size(), ans = 0;
		priority_queue<T> que;
		for (int i=0; i<n; i++)	que.push(T(i, 0, matrix[i][0])); // push每行以第一元素
		while (k-->1) //弹出前k-1个
		{
			T node = que.top(); que.pop();
			if (node.y < n - 1) que.push(T(node.x, node.y + 1, matrix[node.x][node.y + 1])); //之后只需push下一列的元素
		}
		return que.top().t;
	}
};


struct Node
{
	int val;
	int row;
	int col;
	Node(int val = 0,int row = 0, int col = 0) :val(val),row(row), col(col) {}
};

struct cmp
{
	bool operator () (const Node& lhs, const Node& rhs)
	{
		return lhs.val > rhs.val;
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<Node, vector<Node>, cmp> que;
		int n = matrix.size();
		for (int i = 0; i < n; i++) que.push(Node(matrix[0][i], 0, i));
		while (k>1)
		{
			k--;
			int row = que.top().row, col = que.top().col;
			que.pop();
			if (row == n - 1) continue;
			que.push(Node(matrix[row + 1][col], row + 1, col));
		}
		return que.top().val;
	}
};