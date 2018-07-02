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
#include<ctime>
using namespace std;

// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116664/Schematic-explanation-of-two-equivalent-DP-recurrence-formula
const int mod = 1e9 + 7;
class Solution {
public:
	int numTilings(int N) {
		long long  pre[3] = { 1, 1, 2 }, cur;
		if (N < 3) return pre[N];
		for (int i = 3; i <= N; i++)
		{
			cur = pre[2] * 2 + pre[0];
			cur %= mod;
			pre[0] = pre[1];
			pre[1] = pre[2];
			pre[2] = cur;
		}
		return cur;
		
	}
};