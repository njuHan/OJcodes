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


int x[50];
int y[50];
int n;
//求点x0,y0和最近k个点的距离和
int getDistK(int x0, int y0, int k)
{
	multiset<int> st;
	for (int i = 0; i < n; i++)
	{
		int dist = abs(x[i] - x0) + abs(y[i] - y0);
		st.insert(dist);
	}
	int i = 0;
	int sum = 0;
	for (auto e : st)
	{
		if (i >= k) break;
		i++;
		sum = sum + e;
	}
	return sum;
}
/*
这个函数是这道题的关键。由于计算曼哈顿距离时可以通过对x和y分别计算再求和来得到，
所以使dist_sum最小的格子的x坐标一定是X中的一个，y坐标一定是Y中的一个。
 1. 遍历每一个备选格子(X[i], Y[j])，并分别计算dist_sum
 2. 求得它们的最小值
*/
//遍历所有点, 计算累积k和点，所需的最小移动
int minMove(int k)
{
	int move = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int dist = getDistK(x[i], y[j], k);
			move = move > dist ? dist : move;
		}
	return move;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];

	cout << 0; //k == 1;
	for (int k = 2; k <= n; k++)
		cout << " " << minMove(k);
	
	//system("pause");
	return 0;
}


