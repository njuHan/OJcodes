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
using namespace std;

// https://leetcode.com/problems/number-of-digit-one/discuss/64381/4+-lines-O(log-n)-C++JavaPython
class Solution {
public:
	int countDigitOne(int n) {
		int prefix = n, curbit, suffix = 0, m = 1, ans = 0;
		while (prefix>0)
		{
			curbit = prefix % 10;
			prefix /= 10;
			if (curbit == 0)
				ans += prefix*m;
			else if (curbit == 1)
				ans += prefix*m + suffix + 1;
			else
				ans += (prefix + 1) *m;
			//next round
			suffix += curbit*m;
			m *= 10;
		}
		return ans;
	}
	int countDigitOne1(int n) {
		int prefix = n, curbit, suffix = 0, m = 1, ans = 0;
		while (prefix>0)
		{
			curbit = prefix % 10;
			//利用+8 使得cubit>=2时进位+1
			ans += (prefix + 8) / 10 * m + (curbit == 1 ? suffix + 1 : 0);
			prefix /= 10;
			suffix += curbit*m;
			m *= 10;
		}
		return ans;
	}
};

