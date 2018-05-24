#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;


/*
For an n-element permutation, there are (n-1)! permutations started with '1', (n-1)! permutations started with '2', and so forth. Therefore we can determine the value of the first element.

After determining the first element, there are (n-1) candidates left. Then there are (n-2)! permutations started with the minimum element within the remaining set, and so forth.
*/
class Solution {
public:
	string getPermutation(int n, int k) {
		string ans(n,'0');
		int fact = 1;
		for (int i = 1; i <= n; i++)
		{
			ans[i - 1] += i;
			fact *= i;
		}
		for (int i = 0; i < n; i++)
		{
			fact /= n - i;
			int sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (sum + fact >= k) break;
				sum += fact;
				swap(ans[i], ans[i + j]);
			}
			k -= sum;
		}
		return ans;
	}
};