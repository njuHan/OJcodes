#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i<m && j>=0)
		{
			if (matrix[i][j] == target) return true;
			if (matrix[i][j] < target) i++;
			else j--;
		}
		return false;
	}
};