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

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 ) return false;
		if (x != 0 && x % 10 == 0) return false; //Ä©Î²²»ÄÜÎª0
		if (x < 10) return true;
		int res = 0;
		while (x > res)
		{
			res = res * 10 + x % 10;
			x /= 10;
		}
		return x == res || x==res/10; //even || odd
	}
};

int main()
{


	system("pause");
	return 0;
}

