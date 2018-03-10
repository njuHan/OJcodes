#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 当一个最大矩形面积包括整个柱子 i 时，计算该最大面积：
// 1.找到左侧与i距离最近且高度> [i] 的柱子，记下标 p, (若左侧没有，则p=-1)
// 2.找到右侧与i距离最近且高度<= [i] 的柱子，记下标 q，(若右侧没有，则q=len 即最大下标+1)
// 3 面积= [i] * (p - q - 1);
// 对于所有的 i 如上计算即可
// 使用一个栈来记录左侧柱子高度情况，就是需要O(n)时间复杂度
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0); //末尾加个0， 收割leftBars中剩余柱子
		vector<int> leftBars; //设其中的柱子高度严格递增
		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			//这里>=取到等于，当前[i]高度等于栈顶柱子高度，计算栈顶柱子高度时，没有把[i]的面积添加进来
			//但是在下一次计算[i]面积，会把之前和[i]相等的柱子的面积添加进来
			while (leftBars.size() && heights[leftBars.back()] >= heights[i]) 
			{
				int h = heights[leftBars.back()];
				leftBars.pop_back();
				int p = leftBars.size() ? leftBars.back() : -1;
				maxArea = max(maxArea, (i - p - 1)*h);
				//printf("%d -%d -1 * %d, %d\n", i, p, h, maxArea);
			}
			leftBars.push_back(i);
		}
		return maxArea;
	}
};

int main()
{
	vector<int> vec = { 2,1,5,6,2,3 };
	Solution solu;
	int ans = solu.largestRectangleArea(vec);
	printf("%d\n", ans);
	system("pause");
	return 0;
}