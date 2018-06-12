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
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int axorb = 0;
		*num1 = *num2 = 0;
		for (int num : data) axorb ^= num;
		int lowbit = axorb&(-axorb);
		for (int num : data)
		{
			if (num&lowbit) *num1 ^= num;
			else *num2 ^= num;
		}
	}
};