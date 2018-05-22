#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;
		int m = matrix.size(), n = matrix[0].size(), col0 = 1;
		for (int i = 0; i < m; i++)
		{
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < n; j++) //行列标记不能冲突， j从1开始
			{
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
			}
		}
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 1; j--)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (col0 == 0) matrix[i][0] = 0;
		}
	}
};