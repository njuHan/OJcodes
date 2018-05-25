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
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
		{
			ans++;
			n = n&(n - 1);
		}
		return ans;
	}
};