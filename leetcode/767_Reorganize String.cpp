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
	string reorganizeString(string S) {
		int len = S.size();
		if (len < 1) return "";
		if (len == 1) return S;
		map<char, int> chCnt;
		vector<pair<int, char>> cntCh;
		for (char ch : S) chCnt[ch]++;
		for (auto e : chCnt) cntCh.push_back({ e.second, e.first });
		sort(cntCh.rbegin(), cntCh.rend());
		if (cntCh[0].first * 2 > len + 1) return "";

		string sortS, ans;
		for (auto e : cntCh) sortS += string(e.first, e.second);
		int mid = (len + 1) / 2;
		int i = 0, j = mid;
		while (i < mid)
		{
			ans.push_back(sortS[i++]);
			if (j < len) ans.push_back(sortS[j++]);
		}
		return ans;

		
	}
};

int main()
{
	
	system("pause");
	return 0;
}



