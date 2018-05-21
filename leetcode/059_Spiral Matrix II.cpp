#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n < 1) return{};
		vector<vector<int>> ans(n, vector<int>(n, 0));
		int u = 0, d = n - 1, l = 0, r = n - 1, k=1;
		while (true)
		{
			for (int i = l; i <= r; i++) ans[u][i] = k++;
			if (++u > d) break;
			for (int i = u; i <= d; i++) ans[i][r] = k++;
			if (--r < l) break;
			for (int i = r; i >= l; i--) ans[d][i] = k++;
			if (--d < u) break;
			for (int i = d; i >= u; i--) ans[i][l] = k++;
			if (++l > r) break;
		}
		return ans;
	}
};