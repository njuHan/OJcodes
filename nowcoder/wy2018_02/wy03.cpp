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

const int maxn = 55;
int arr[maxn];
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	if (len < 1)
	{
		cout << "0" << endl;
		return 0;
	}
	vector<int> dp(len, 0);
	dp[0] = 1;
	int maxcnt=1;
	for (int i = 1; i < len; i++)
	{
		if (str[i] != str[i - 1]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
		maxcnt = max(maxcnt, dp[i]);
	}
	cout << maxcnt;
	//system("pause");
	return 0;
}


