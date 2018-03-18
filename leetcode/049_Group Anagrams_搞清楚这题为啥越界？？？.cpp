#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<assert.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
		//unordered_map<long long, int> key2idx = unordered_map<long long, int>();
		map<long long, size_t> key2idx;
		size_t mapSize = 0;
		vector<vector<string>> ans;
		for (size_t i = 0; i < strs.size(); i++)
		{
			long long key = 1;
			for (size_t j = 0; j < strs[i].size(); j++)
			{
				// 为了防止溢出可以 乘完%一个大质数
				key *= prime[strs[i][j] - 'a'];
			}
			if (key2idx.count(key) == 0)
			{
				// 这里越界是因为执行左侧时，size已经+1了
				//key2idx[key] = key2idx.size();
				key2idx[key] = mapSize++;
				ans.push_back({ strs[i] });
			}
			else
			{
				size_t idx = key2idx[key];
				assert(idx < ans.size()); 
				ans[idx].push_back(strs[i]);
			}
		}
		return ans;
	}

};

int main()
{
	Solution solu;
	vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ans = solu.groupAnagrams(vec);
	for (size_t i = 0; i < ans.size(); i++)
	{
		for (size_t j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ",";
		printf("\n");
	}
	system("pause");
	return 0;
}