#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

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
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size()==0) return 0; //注意空mat
		int m = matrix.size(), n = matrix[0].size(); //行列
		int maxRec = 0;
		vector<int> heights(n, 0);
		for (int i = m - 1; i >= 0; i--)
		{
			int idx = i; 
			int h = 0;
			for (int j = 0; j < n; j++)
			{
				while (idx >= 0 && matrix[idx][j] != '0')
				{
					h++;
					idx--;
				}
				heights[j] = h;
				h = 0;
				idx = i;
			}
			maxRec = max(maxRec, largestRectangleArea(heights));
		}
		return maxRec;
	}
};

int main()
{
	vector<vector<char>> mat = { { '1' ,'0', '1', '0', '0'},
	{'1', '0', '1','1', '1'},
	{'1', '1', '1', '1', '1'},
	{'1','0', '0', '1', '0' }};

	Solution solu;
	int ans = solu.maximalRectangle(mat);
	printf("%d\n", ans);
	system("pause");
	return 0;
}