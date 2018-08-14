#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

// update 2018-08-14, backtracking
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		search(0, "", digits);
		return ans;
	}
private:
	vector<string> ans;
	static  vector<string> dig2let;
	void search(int cur, string str, string& digits)
	{
		if (cur == digits.length() && str.length()) 
        {
            ans.emplace_back(str);
            return;
        }
		int dig = digits[cur] - '0';
		if (dig < 1 || dig>9) return search(cur + 1, str, digits);
		for (char ch : dig2let[dig])
		{
			str.push_back(ch);
			search(cur + 1, str, digits);
			str.pop_back();
		}
	}
};
vector<string> Solution::dig2let = { "","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


// 以下是几个月前写的，感觉不行

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