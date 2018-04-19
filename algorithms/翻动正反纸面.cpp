#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
using namespace std;

//一堆纸随机正反面向上，每次只能翻动最上面k张纸，全部正面向上需要多少次翻动
//1:正面向上，0反面
int func(vector<int> paper)
{
	int n = paper.size();
	if (n == 0) return 0;
	int ans = 1;
	int state = paper[0];
	for (int i = 0; i < n; i++)
	{
		if (paper[i] != state)
		{
			state = paper[i];
			ans++; //不同段加一
		}
	}
	return paper[n - 1] == 1 ? ans - 1 : ans;
}