#include<iostream>
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
	int numSimilarGroups(vector<string>& A) {
		int cnt = 0, len = A.size();
		for (int i = 0; i < len; i++) //必须从 0 开始
		{
			if (pa.count(A[i])) continue;
			pa[A[i]] = A[i];
			cnt++;
			for (int j = 0; j < i; j++)
			{
				if (isSame(A[j], A[i]))
				{
					string x = find(A[j]), y = find(A[i]);
					if (x != y)
					{
						cnt--;
						pa[y] = x;
					}
				}
			}
		}
		return cnt;
	}
private:
	unordered_map<string, string> pa;
	bool isSame(string& lhs, string& rhs)
	{
		int cnt = 0;
		for (int i = 0; i < lhs.length(); i++)
			if (lhs[i] != rhs[i] && ++cnt>2) return false;
		return true;
	}
	string find(string str)
	{
		return pa[str] == str ? str : pa[str] = find(pa[str]);
	}
};