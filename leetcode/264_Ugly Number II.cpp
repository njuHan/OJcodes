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
#include<sstream>
using namespace std;


class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 1) return 1;
		vector<int> nums(n);
		nums[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		int next = 1;
		while (next<n)
		{
			int u = min({ nums[p2] * 2, nums[p3] * 3,  nums[p5] * 5 });
			nums[next++] = u; //insert first
			while (nums[p2] * 2 <= u) p2++;
			while (nums[p3] * 3 <= u) p3++;
			while (nums[p5] * 5 <= u) p5++;
		}
		return nums[n - 1];
	}
};
