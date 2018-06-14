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
	int numJewelsInStones(string J, string S) {
		unordered_set<char> st(J.begin(), J.end());
		int cnt = 0;
		for (char ch : S)
			if (st.count(ch)) cnt++;
		return cnt;
	}
};