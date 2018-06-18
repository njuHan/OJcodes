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
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows < 1) return ans;
		ans.push_back({ 1 });
		for (int i = 1; i < numRows; i++)
		{
			vector<int> vec(i + 1, 1);
			for (int j = 0; j < vec.size(); j++)
			{
				if (j - 1 >= 0 && j < i)
					vec[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans.push_back(vec);
		}
		return ans;
	}
};