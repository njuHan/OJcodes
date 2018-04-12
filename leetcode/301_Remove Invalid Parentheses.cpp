#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		dfsRemove(0, 0, s, "()");
		return ans;
	}
	
private:
	vector<string> ans;
	//在遍历的时候发现 ) 多于 ( ，就可以确定需要删除 )， eg: ()))) 
	//逆序后 以上情况相反 ((() 逆序->  )(((, 可以确定要删除的 (
	//去重： 连续的要删除括号，我们选择第一个删除， lastRm标记上一次删除的idx
	//666 solution : https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/Easy-Short-Concise-and-Fast-Java-DFS-3-ms-solution
	void dfsRemove(int start, int lastRm, string s, const string& par)
	{
		int cnt = 0;
		for (int i = start; i < s.size(); i++)
		{
			if (par[0] == s[i]) cnt++;
			if (par[1] == s[i]) cnt--;
			if (cnt >= 0) continue; //此时不能确定需不需要删除括号
			// else cnt<0 ，此时就需要删除 par[1], dfs回溯删除
			//[start, i]这段区间多了一个par[1]
			for (int j = lastRm; j <= i; j++)
			{
				//在区间[lastRm, i]中删了一个字符par[1]
				//讨论下一个区间[i, len], 由于删除以个字符，所以从i开始
				if (s[j] == par[1] && (j == lastRm || s[j - 1] != par[1]))
					dfsRemove(i, j, s.substr(0, j) + s.substr(j + 1), par);
			}
			return; //处理了cnt<0的情况，无需继续处理cnt>=0，直接返回
		}
		//代码复用处理 cnt>=0
		//逆序处理了cnt>0之后， 还会逆序一次(cnt==0)，使得和源序列一样
		reverse(s.begin(), s.end());
		if (par[0] == '(')
			dfsRemove(0, 0, s, ")(");
		else
			ans.emplace_back(s);
	}
};

int main()
{

}