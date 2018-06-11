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
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len != 5) return 0;
		sort(numbers.begin(), numbers.end());
		int cnt0 = 0, gap = 0;
		while (numbers[cnt0] == 0) cnt0++;
		for (int j = cnt0; j < len - 1; j++)
		{
			if (numbers[j + 1] == numbers[j]) return false;
			gap += numbers[j + 1] - numbers[j] - 1;
		}
		return cnt0 >= gap;
	}
};
