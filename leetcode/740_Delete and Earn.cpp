#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;


class Solution {
public:
	//对于buckets[i], takei必须基于skip[i-1]
	//skipi, 可以基于take[i-1] 或 skip[i-1]
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() < 1) return 0;
		map<int, int> buckets;
		for (int num : nums)
		{
			buckets[num] += num;
		}
		//找到最小最大的num
		int mini = buckets.begin()->first;
		int maxi = buckets.rbegin()->first;

		//之前的取或不取的值
		int take = 0, skip = 0;
		//当前取 或者 不取
		int takeCur, skipCur;
		for (int i = mini; i<=maxi; i++)
		{
			takeCur = skip + buckets[i];
			skipCur = max(take, skip);
			take = takeCur;
			skip = skipCur;
		}
		return max(take, skip);
	}
};


int main()
{

	

	system("pause");
	return 0;
}



