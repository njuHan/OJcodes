#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	//stack method
	int longestValidParentheses_stack(string s) {
		int len = s.size();
		if (len <= 1) return 0;
		stack<int> sk;
		sk.push(-1);
		int maxLen = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(') 
				sk.push(i);
			else
			{
				sk.pop();
				if (sk.empty()) // pop 出来的是')' 
					sk.push(i); // 将新的')'的下标 i push 进来
				else 
					maxLen = max(maxLen, i - sk.top());
			}
			
		}
		return maxLen;
	}
	// dp method
	int longestValidParentheses(string s)
	{
		int len = s.size();
		if (len <= 1) return 0;
		vector<int> dp(len, 0);
		int maxLen = 0;
		for (int i = 1; i < len; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = i >= 2 ?  (dp[i-2] + 2) :  2;
				}
				else //s[i]==')'
				{
					int idx = i - dp[i - 1] - 1;
					if (idx >= 0 && s[idx] == '(')
						dp[i] = idx >0 ? (dp[idx-1] + dp[i - 1] + 2) : (dp[i-1] + 2) ;
				}
				maxLen = max(maxLen, dp[i]);
			}
			
		}
		return maxLen;
	}
};

int main()
{
	

	Solution solu;
	int ans = solu.longestValidParentheses("(()())");
	printf("%d\n", ans);
	system("pause");
	return 0;
}