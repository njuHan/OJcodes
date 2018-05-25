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
	vector<string> fizzBuzz(int n) {
		string fizz = "Fizz", buzz = "Buzz";
		vector<string> ans;
		for (int i = 1; i <= n; i++)
		{
			if (i % 15 == 0) ans.emplace_back(fizz + buzz);
			else if (i % 3 == 0) ans.emplace_back(fizz);
			else if (i % 5 == 0) ans.emplace_back(buzz);
			else ans.emplace_back(to_string(i));
		}
		return ans;
	}
};