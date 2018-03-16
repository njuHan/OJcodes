#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int len = nums.size();
		if (len < 4) return false;
		int sum = 0;
		for (int i = 0; i < len; i++) sum += nums[i];
		if (sum % 4) return false;
		//从大到小排序，有利于提前跳出递归，防止指数爆炸
		sort(nums.rbegin(), nums.rend());
		// 4个边，每个元素必须选择一个边放入，以此回溯
		this->edgeLen = sum / 4;
		int edge[4] = {0,0,0,0};
		return getEdge(0, edge, nums);
	}
	bool getEdge(int cur, int edge[], vector<int>& nums)
	{
		if (cur == nums.size())
		{ 
			bool flag = true;
			for (int i = 0; i < 4; i++) flag = flag && (edge[i] == edgeLen);
			return flag;
		}
		for (int i = 0; i < 4; i++)
		{
			if (edge[i] + nums[cur] <= edgeLen)
			{
				edge[i] += nums[cur];
				if (getEdge(cur + 1, edge, nums))
					return true;
				edge[i] -= nums[cur];
			}
		}
		return false;
	}
	
private:
	
	int edgeLen;
};

int main()
{
	Solution solu;
	vector<int> vec = { 8,16,24,32,40,48,56,64,72,80,88,96,104,112,60 }; //{ 1, 1, 2, 2, 2 }; //
	bool ans = solu.makesquare(vec);
	cout << ans;
	system("pause");
	return 0;
}