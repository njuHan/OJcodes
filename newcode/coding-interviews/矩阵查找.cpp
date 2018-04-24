#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int m = array.size(), n;
		if (m == 0 || (n = array[0].size()) == 0) return 0;
		int i = 0, j = n - 1;
		while (i<m && j>=0)
		{
			if (target == array[i][j])
				return 1;
			else if (target < array[i][j])
				j--;
			else 
				i++;
		}
		return 0;
	}
};