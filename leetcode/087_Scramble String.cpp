#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<string, bool> isValid;
	bool isScramble(string s1, string s2) {
		if (s1 == s2) return true; //最终会递归到单个字母比较
		int m = s1.size(), n = s2.size();
		if (m != n) return false;
		if (isValid.count(s1 + s2)) return isValid[s1 + s2];
		//cout << s1 << "  " << s2 << endl;
		for (int i = 1; i < m; i++) //注意这里下标从1开始，否则会不断重复调用自己
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, m - i), s2.substr(i, m - i)))
				return isValid[s1 + s2] = true;
			if (isScramble(s1.substr(0, i), s2.substr(m - i, i)) && isScramble(s1.substr(i, m - i), s2.substr(0, m-i)))
				return isValid[s1 + s2] = true;
		}
		return isValid[s1 + s2] = false;
		
	}

};

int main()
{
	Solution solu;

	bool ans = solu.isScramble("great", "rgeat");
	printf("%d\n", ans);
	system("pause");
	return 0;
}