#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		int curlen = 0, cnt, len = words.size(), i = 0;
		while ( i < len)
		{
			curlen = words[i++].length();
			cnt = 1;
			while (i < len && curlen + 1 + words[i].length()<=maxWidth)
			{
				curlen += (1 + words[i++].length());
				cnt++;
			}
			string line;
			int k = i - cnt;
			if (cnt == 1)
			{
				line += words[k];
				line += string(maxWidth - curlen, ' ');
			}
			else if (i == len)
			{
				for (int j = 0; j < cnt; j++)
				{
					line += words[k++];
					if (j < cnt - 1) line += " ";
				}
				line += string(maxWidth - curlen, ' ');
			}
			else
			{
				int spacelen = cnt - 1 + maxWidth - curlen;
				int n = spacelen / (cnt - 1);
				int m = spacelen % (cnt - 1);
				for (int j = 0; j < cnt; j++)
				{
					line += words[k++];
					if (j < cnt - 1) line += string(n + (j < m), ' ');
				}
			}
			ans.push_back(line);
		}
		return ans;
	}
};