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
#include<sstream>
#include<functional>
using namespace std;

// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C++-codes-with-explanation-and-references
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), ans = INT_MIN;
		for (int left = 0; left < n; left++)
		{
			vector<int> rowSum(m, 0);
			for (int j = left; j < n; j++)
			{
				for (int i = 0; i < m; i++)
				{
					rowSum[i] += matrix[i][j];
				}

				set<int> st;
				int accuSum = 0; //累积sum
				st.insert(0);
				for (int sum : rowSum)// 注意不能使用变量k迭代
				{
					accuSum += sum;
					auto  pos = lower_bound(st.begin(), st.end(), accuSum - k);
					if (pos != st.end()) ans = max(ans, accuSum - *pos);
					st.insert(accuSum);
				}
			}
		}
		return ans;
	}
};