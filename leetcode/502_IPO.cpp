#include<iostream>
#include<cstdio>
#include<assert.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		vector<pair<int, int> > data;
		int curcap = W;
		for (int i = 0; i < Capital.size(); i++)
		{
			data.emplace_back(make_pair(Profits[i], Capital[i]));
		}
		sort(data.begin(), data.end());
		for (int i = data.size() - 1; i >= 0 && k>0; i--)
		{
			if (data[i].second <= curcap)
			{
				curcap += data[i].first;
				data.erase(data.begin() + i);
				i = data.size();
				k--;
			}
		}
		return curcap;
	}
};

int main()
{
	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 0,1,1 };
	Solution solu;
	solu.findMaximizedCapital(2, 0, v1, v2);
	system("pause");
	return 0;
}