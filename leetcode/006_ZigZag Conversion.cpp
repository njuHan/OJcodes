#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		if (len <= 1 || numRows <= 1) return s;
		
		int offset = numRows + numRows - 2;
		int len1, len2;
		if (len%offset < numRows) len1 = len / offset + 1;
		else len1 = len / offset + 2;
		len2 = (len1 - 1) * 2 + 1;
		vector<vector<int>> idx(numRows, vector<int>(len2, -1));
		for (int i = 0; i < len2; i += 2)
		{
			idx[0][i] = offset*(i/2);
		}
		
		for (int i = 0; i < len2; i += 2)
		{
			idx[numRows - 1][i] = numRows - 1 + offset*(i / 2);
		}

		if (1<numRows-1)
			for (int j = 0; j < len2; j++)
			{
				if (idx[0][j] == -1) idx[1][j] = idx[0][j + 1] - 1;
				else idx[1][j] = idx[0][j] + 1;
			}
		
		for (int i = 2; i < numRows - 1; i++)
		{
			int p = 1;
			for (int j = 0; j < len2; j++)
			{
				idx[i][j] = idx[i - 1][j] + p;
				p = -p;
			}
		}
		string ans = "";
		for (int i = 0; i < numRows; i++)
			for (int j = 0; j < len2; j++)
			{
				if (idx[i][j] != -1 && idx[i][j] < len)
					ans.push_back(s[idx[i][j]]);
			}
		return ans;
	}
};

int main()
{
	Solution solu;
	string ans = solu.convert("PAYPALISHIRING", 4);
	system("pause");
	return 0;
}