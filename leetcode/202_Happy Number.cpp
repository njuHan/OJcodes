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
	bool isHappy(int n) {
		while (n!=1 && !cnt.count(n))
		{
			int sum = 0;
			while (n)
			{
				sum += (n % 10)*(n % 10);
				n /= 10;
			}
			n = sum;
			cnt[n]++;
		}
		return n == 1;
	}
private:
	unordered_map<int, int> cnt;
};