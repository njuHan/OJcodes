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