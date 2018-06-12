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
	int GetNumberOfK(vector<int> data, int k) {
		//return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
		return upper(data, k) - lower(data, k);
	}
private:
	int lower(vector<int>& data, int num)
	{
		int x = 0, y = data.size();
		while (x<y)
		{
			int mid = x + (y - x) / 2;
			if (data[mid] >= num) y = mid;
			else x = mid + 1;
		}
		return x;
	}
	int upper(vector<int>& data, int num)
	{
		int x = 0, y = data.size();
		while (x<y)
		{
			int mid = x + (y - x) / 2;
			if (data[mid] <= num) x = mid+1;
			else y = mid;
		}
		return x;
	}
};
