#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;

//https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method?page=3

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		const int maxn = 26;
		vector<int> svec(maxn, 0);
		vector<int> pvec(maxn, 0);
		vector<int> ans;
		int slen = s.size(), plen = p.size();
		if (slen < plen) return ans;
		for (int i = 0; i < plen; i++)
		{
			svec[s[i] - 'a']++;
			pvec[p[i] - 'a']++;
		}
		if (svec == pvec) ans.emplace_back(0);
		for (int i = plen; i < slen; i++)
		{
			svec[s[i] - 'a']++;
			svec[s[i - plen] - 'a']--;
			if (svec == pvec)
				ans.emplace_back(i - plen + 1);
		}
		return ans;
	}
};

int main()
{

	return 0;
}