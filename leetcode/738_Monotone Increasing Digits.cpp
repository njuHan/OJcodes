#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		string str = to_string(N);
		int len = str.size();
		if (len <= 1) return N;
		int i, j = 0;
		for (i = 1; i < len; i++)
		{
			if (str[i] > str[i-1])
			{
				j = i;
			}
			else if (str[i]<str[i-1])
			{
				break;
			}
		}
		if (i == len) return N;
		str[j]--;
		j++;
		while (j<len)
		{
			str[j] = '9';
			j++;
		}
		return atoi(str.c_str());
	}
};

int main()
{

	Solution solu;
	solu.monotoneIncreasingDigits(10);
	
	system("pause");
	return 0;
}



