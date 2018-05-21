#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

static int ___ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int mySqrt(int x) {
		long long r = x;
		while (r*r > x)
		{
			r = (r + x / r) >> 1;
		}
		return r;
	}
};