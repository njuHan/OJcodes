#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>

using namespace std;

class Solution {
public:
	/*
	If car starts at A and can not reach B. Any station between A and B
	can not reach B.(B is the first station that A can not reach.)
	If the total number of gas is >= the total number of cost. There must be a solution.
	*/
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		if (len < 1) return 0;
		int start = 0, cur = 0, diff = 0;
		for (int i = 0; i < len; i++)
		{
			diff += (gas[i] - cost[i]);
			cur = cur + gas[i] - cost[i];
			if (cur < 0) //can't reach i, new start from i+1
			{
				start = i + 1;
				cur = 0;
			}
		}
		return diff >= 0 ? start : -1;
	}
};
int main()
{


	system("pause");
	return 0;
}

