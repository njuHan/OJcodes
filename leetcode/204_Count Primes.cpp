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
	// https://leetcode.com/problems/count-primes/discuss/57588/My-simple-Java-solution
	int countPrimes(int n) {
		int ans = 0;
		vector<bool> isPrime(n, true);
		for (int i = 2; i < n; i++)
		{
			if (isPrime[i])
			{
				ans++;
				if (i > sqrt(n)) continue;
				for (int j = i*i; j < n; j += i)
				{
					isPrime[j] = false;
				}
			}
		}
		return ans;
	}
};