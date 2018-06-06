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
#include<ctime>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int lo = 0, hi = numbers.size()-1;
		while (lo<hi)
		{
			if (numbers[lo] + numbers[hi] == target) break;
			else if (numbers[lo] + numbers[hi] < target) lo++;
			else hi--;
		}
		return{ lo + 1,hi + 1 };
	}
};