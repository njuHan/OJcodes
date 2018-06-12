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
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum < 2) return ans; //at least 2 numbers
		int lo = 1, hi = 1, mid = sum / 2, cur = 1;
		vector<int> vec = { 1 };
		while (lo<=mid)
		{
			cur += ++hi;
			vec.push_back(hi);
			if (cur == sum) pushAns(lo, hi);
			while (lo<=mid && cur>sum)
			{
				cur -= lo++;
				if (cur == sum) pushAns(lo, hi);
			}
		}
		return ans;
	}
private:
	vector<vector<int>> ans;
	void pushAns(int lo, int hi)
	{
		vector<int> vec;
		for (int i = lo; i <= hi; i++) vec.emplace_back(i);
		ans.emplace_back(vec);
	}
};

int main()
{
	Solution solu;
	vector<vector<int>> ans = solu.FindContinuousSequence(100);

	system("pause");
	return 0;
}