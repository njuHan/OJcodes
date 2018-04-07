#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels2(string S) {
		vector<int> ans;
		int i = 0;
		while (i < S.size())
		{
			int end = S.find_last_of(S[i]);
			int j = i;
			while (j < end)
			{
				end = max((int)S.find_last_of(S[j++]), end);
			}
			ans.push_back(end - i + 1);
			i = end + 1;
		}
		return ans;
	}
	vector<int> partitionLabels(string S) {
		vector<int> ans;
		unordered_map<char, int> ch2idx;
		for (int i = 0; i < S.size(); i++) ch2idx[S[i]] = i; //记录最大下标
		int i = 0;
		while (i < S.size())
		{
			int end = ch2idx[S[i]];
			int j = i;
			while (j < end) end = max(end, ch2idx[S[j++]]);
			ans.push_back(end - i + 1);
			i = end + 1;
		}
		return ans;
	}
};
int main()
{
	string s = "abcab";
	int end = s.find_last_of('a');
	cout << end;
	system("pause");
	return 0;
}



