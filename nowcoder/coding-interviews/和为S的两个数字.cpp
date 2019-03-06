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
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> ans;
		int lo = 0, hi = array.size() - 1;
		if (hi < 1) return ans;
		while (lo<hi)
		{
			if (array[lo] + array[hi] == sum)
			{
				ans = { array[lo], array[hi] };
				break;
			}
			else if (array[lo] + array[hi] < sum) lo++;
			else hi--;
		}
		return ans;
	}
};

int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}