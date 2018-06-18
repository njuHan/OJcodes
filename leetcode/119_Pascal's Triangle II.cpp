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
	vector<int> getRow(int rowIndex) {
		vector<int> ans = vector<int>(rowIndex + 1, 1);
		for (int i = 1; i <= rowIndex; i++)
		{
			long long temp = (long long)ans[i - 1] * (rowIndex - i + 1) / i;
			ans[i] = (int)temp;
		}
		return ans;
	}
};