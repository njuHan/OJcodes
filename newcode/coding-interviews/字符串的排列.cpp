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


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<string> Permutation(string str) {
		int len = str.length();
		if (len < 1) return ans;
		sort(str.begin(), str.end());
		this->str = str;
		for (char ch : str) unused[ch]++;
		string permu(len,0);
		dfs(0, permu);
		return ans;
	}
private:
	vector<string> ans;
	string str;
	unordered_map<char, int> unused;
	void dfs(int cur, string& permu )
	{
		if (cur == str.length())
		{
			ans.push_back(permu);
			return;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (i > 0 && str[i - 1] == str[i]) continue;
			if (unused[str[i]] == 0) continue;
			unused[str[i]]--;
			permu[cur] = str[i];
			dfs(cur + 1, permu);
			unused[str[i]]++;;
			
		}
	}
};
int main()
{
	string str = "abc";
	Solution solu;
	vector<string> ans = solu.Permutation(str);
	system("pause");
	return 0;
}