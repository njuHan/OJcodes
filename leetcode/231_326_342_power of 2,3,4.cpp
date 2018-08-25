#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
#include<math.h>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		// 新增test case: n = INT_MIN, n-1溢出
		long long m = (long long)n;
        return m && (m&(m-1))==0;
	}
	bool isPowerOfThree(int n) {
		return fmod(log10(n) / log10(3), 1) == 0;
	}

	bool isPowerOfFour(int num) {
		//return num>0 && (num&(num - 1)) == 0 && (num & 0x55555555) == num;
		return num > 0 && (num&(num - 1)) == 0 && (num - 1) % 3 == 0;
	}
};