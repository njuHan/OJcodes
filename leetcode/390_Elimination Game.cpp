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
#include<ctime>
using namespace std;


class Solution {
public:
	int lastRemaining(int n) {
		int head = 1, remain = n, step = 1;
		bool fromLeft = 1;
		while (remain>1)
		{
			if (fromLeft || remain & 1 == 1)
				head = head + step;
			step <<= 1;
			remain >>= 1;
			fromLeft = !fromLeft;
		}
		return head;
	}
};