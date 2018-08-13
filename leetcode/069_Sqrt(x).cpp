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

class Solution2 {
public:
    int mySqrt(int x) {
        if (x<=1) return x;
        int ans = 0;
        int lo = 1, hi = x;
        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if (mid <= x/mid ) ans = mid, lo = mid+1; // x/mid 防溢出
            else hi = mid;
        }
        return ans;
    }
};