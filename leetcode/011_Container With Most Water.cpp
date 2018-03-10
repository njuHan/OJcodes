#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int low = 0, high = len - 1;
		int maxarea = (high - low)*min(height[low], height[high]);
		while (low < high)
		{
			maxarea = max(maxarea, (high - low)*min(height[low], height[high]));
			if (height[low] < height[high])
				low++;
			else
				high--;

		}
		return maxarea;
	}
};

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	Solution solu;
	int ans = solu.maxArea(v);
	printf("%d\n", ans);
	system("pause");
	return 0;
}