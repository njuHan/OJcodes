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
	int trailingZeroes(int n) {
		return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
	}
};