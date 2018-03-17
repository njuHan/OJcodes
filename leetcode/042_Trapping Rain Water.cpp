#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) 
	{
		stack<int> sk;
		int sum = 0;
		for (int i = 0; i < height.size(); i++)
		{
			//计算栈顶柱子雨水面积
			while (!sk.empty() && height[i] > height[sk.top()])
			{
				int h = height[sk.top()];
				sk.pop();
				if (!sk.empty())
				{
					int rh = height[i];
					int lh = height[sk.top()];
					int s = (i - sk.top() - 1)*(min(lh, rh) - h);
					sum += s;
				}

			}
			if (sk.empty())
				sk.push(i);
			else if (height[i] < height[sk.top()])
				sk.push(i);
			else if (height[i] == height[sk.top()])
			{
				sk.pop();
				sk.push(i);
			}
		}
		return sum;
	}
};
int main()
{
	Solution solu;
	vector<int > vec = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ans = solu.trap(vec);
	cout << ans;
	system("pause");
	return 0;
}