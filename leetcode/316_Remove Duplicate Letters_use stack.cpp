#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		unordered_map<char, int> chCnt;
		vector<bool> vis(256, 0);
		for (char ch : s) chCnt[ch]++;
		string ans;
		for (char ch : s)
		{
			chCnt[ch]--;
			if (vis[ch]) continue;
			while (!ans.empty() && chCnt[ans.back()]>0 && ch<ans.back())
			{
				vis[ans.back()] = false;
				ans.pop_back();
			}
			ans.push_back(ch);
			vis[ch] = true;
		}
		return ans;
	}
};

int main()
{

	
	system("pause");
	return 0;
}