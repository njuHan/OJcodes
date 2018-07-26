#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<bitset>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		bitset<32> xbit(x);
		bitset<32> ybit(y);
		bitset<32> ans = xbit^ybit;
		return ans.count();
	}
	int hammingDistance2(int x, int y) {
		int ans = 0;
		int temp = x^y;
		while (temp)
		{
			ans += temp & 1;
			temp = temp >> 1;
		}
		return ans;
	}
	int hammingDistance3(int x, int y) {
       int ans = 0;
		int temp = x^y;
		while (temp)
		{
			ans++;
			temp = temp & (temp-1);
		}
		return ans;
    }
};