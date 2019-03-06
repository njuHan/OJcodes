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
#include<functional>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || str == NULL || strlen(str)==0 || rows*cols<=0) return false;
		this->matrix = matrix; this->str = str;
		m = rows; n = cols;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i*n + j] == str[0] && search(i, j, 0)) return true;
		return false;
	}
private:
	char* matrix;
	char* str;
	int m, n;
	bool search(int i, int j, int cur)
	{
		if (cur == strlen(str)) return true;
		if (i < 0 || i >= m || j < 0 || j >= n ||  matrix[i*n+j]!=str[cur]) return false;
		char temp = matrix[i*n + j];
		matrix[i*n + j] = '#';
		bool ans = (search(i - 1, j, cur + 1) || search(i + 1, j, cur + 1) || search(i, j - 1, cur + 1) || search(i, j + 1, cur + 1));;
		matrix[i*n + j] = temp;
		return ans;

	}

};