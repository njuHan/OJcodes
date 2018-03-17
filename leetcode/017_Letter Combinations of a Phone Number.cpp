#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

//这题类似BFS，一开始想到用queue，但是觉得队列取个元素还要两个操作麻烦
//其实用vector自己控制访问顺序就行了
//另外vector的深拷贝和浅拷贝了解下
//emplace_back 了解下

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> dig2let = { "","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ans;
		int len = digits.size();
		if (len < 1) return ans;
		ans.push_back("");
		for (int i = 0; i < len; i++)
		{
			int dig = digits[i] - '0';
			if (dig < 0 || dig>9) break;
			vector<string> temp;
			for (int j = 0; j < dig2let[dig].size(); j++)
			{
				for (int k = 0; k < ans.size(); k++)
				{
					//temp.push_back(ans[k] + dig2let[dig][j]);
					temp.emplace_back(ans[k] + dig2let[dig][j]);
				}
			}
			ans.swap(temp);
		}
		return ans;
	}
};
int main()
{
	Solution solu;
	vector<string> ans = solu.letterCombinations("23");
	for (auto e : ans)
		cout << e << endl;
	system("pause");
	return 0;
}