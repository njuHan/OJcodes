#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		for (int i = 0; i < 32; i++)
		{
			ans = ans << 1;
			ans = ans | (n & 1);
			n = n >> 1;
		}
		return ans;
	}

	uint32_t reverseBits2(uint32_t n) {
		uint32_t ans = 0, one = 1;;
		for (int i = 0; i < 32; i++)
		{
			if (n&one)
				ans = ans | (1 << (31 - i));
			one = one << 1;
		}
		return ans;
	}

	uint32_t reverseBits3(uint32_t n) {
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}

	uint32_t reverseBits4(uint32_t n) {
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = (n >> 16) | (n << 16);
		return n;
	}
};