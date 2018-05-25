#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52470/4-lines-4ms-C++-Solution-with-Explanations

class Solution {
public:
	int trailingZeroes(int n) {
		return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
	}
};