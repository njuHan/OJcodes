#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> sumCnt;
		int ans = 0;
		for (int a : A)
			for (int b : B)
			{
				sumCnt[a + b]++;
			}
		for (int c : C)
			for (int d : D)
			{
				if (sumCnt.count(-c - d))
					ans += sumCnt[-c - d];
			}
		return ans;
	}
};