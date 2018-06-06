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
using namespace std;

// https://leetcode.com/problems/gray-code/discuss/29881/An-accepted-three-line-solution-in-JAVA
// The idea is simple. G(i) = i^ (i/2).
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		for (int i = 0; i < (1 << n); i++)
			ans.emplace_back(i ^ (i >> 1));
		return ans;
	}
};