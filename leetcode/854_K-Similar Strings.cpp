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
#include<sstream>
#include<functional>
using namespace std;

class Solution {
public:
	// bfs 每次swap一次，匹配数+1
	int kSimilarity(string A, string B) {
		if (A == B) return 0;
		queue<string> que;
		unordered_set<string> vis;
		que.push(A);
		int ans = 0, len = A.length();
		while (!que.empty())
		{
			ans++;
			int m = que.size(), i=0;
			while (m--)
			{
				string str = que.front(); que.pop();
				i = 0;
				while (str[i] == B[i]) i++;
				for (int j = i + 1; j < len; j++)
				{
					if (str[j] != B[j] && str[j] == B[i])
					{
						string temp = str;
						swap(temp[i], temp[j]);
						if (temp == B) return ans;
						if (vis.insert(temp).second) que.push(temp);
						
					}
				}
			}
		}
		return ans;
	}
};