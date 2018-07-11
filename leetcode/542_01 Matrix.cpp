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
#include<ctime>
#include<numeric>
using namespace std;

// dp solution 
// https://leetcode.com/problems/01-matrix/discuss/101039/Java-33ms-solution-with-two-sweeps-in-O(n)

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty()) return matrix;
		int m = matrix.size(), n = matrix[0].size();
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				if (matrix[i][j] == 1)
				{
					matrix[i][j] = INT_MAX;
					if (i > 0 && matrix[i - 1][j] != INT_MAX) matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
					if (j > 0 && matrix[i][j - 1] != INT_MAX) matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
				}
		for (int i = m-1; i>=0; i--)
			for (int j = n-1; j>=0; j--)
			{   
				// relax
				if (i + 1 < m && matrix[i + 1][j] != INT_MAX) matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
				if (j + 1 < n && matrix[i][j + 1] != INT_MAX) matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
			}
		return matrix;
	}
};