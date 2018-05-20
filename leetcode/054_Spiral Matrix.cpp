#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size(), n;
		if (m == 0 || (n = matrix[0].size()) == 0) return{};
		vector<int> ans(m*n);
		int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
		while (true)
		{
			for (int i = l; i <= r; i++) ans[k++] = matrix[u][i];
			if (++u > d) break;
			for (int i = u; i <= d; i++) ans[k++] = matrix[i][r];
			if (--r < l) break;
			for (int i = r; i >= l; i--) ans[k++] = matrix[d][i];
			if (--d < u) break;
			for (int i = d; i >= u; i--) ans[k++] = matrix[i][l];
			if (++l > r) break;
		}
		return ans;
	}
};