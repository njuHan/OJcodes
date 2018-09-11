#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
   vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (n <= 0) return ans;
		string s = "";
		getP(ans, s, 0, 0, n);
		return ans;
	}
	void getP(vector<string>& ans, string s, int diff, int cur, int n)
	{
		if (cur == 2 * n && diff == 0)
			ans.push_back(s);
		else if (cur < 2*n)
		{
            if (diff > 2*n-cur) return; //pruning
			s.push_back('(');
            getP(ans, s, diff + 1, cur + 1, n);
            s.pop_back();
            if (diff > 0)
			{
				s.push_back(')');
				getP(ans, s, diff - 1, cur + 1, n);
			}
			
		}

	}
};

int main()
{
	Solution solu;
	vector<string> ans = solu.generateParenthesis(3);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	system("pause");
	return 0;
}