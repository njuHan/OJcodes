#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n;
		if (m == 0 || (n = matrix[0].size()) == 0) return false;
		int r = 0, c = n - 1;
		while (r<m && c>=0)
		{
			if (target > matrix[r][c])
				r++;
			else if (target < matrix[r][c])
				c--;
			else return true;
		}
		return false;
	}
};
int main()
{


	system("pause");
	return 0;
}



