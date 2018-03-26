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




int main()
{
	
	int n, l;
	cin >> n >> l;
	int temp = n - 1;
	vector<int> depth(n, 0);
	int maxdep = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		int v;
		cin >> v;
		depth[i] = depth[v] + 1;
		maxdep = maxdep < depth[i] ? depth[i] : maxdep;
	}
	//贪心，走最长路径结点的边只需走一次，
	//其他结点的边需要走2次
	int cnt;
	if (maxdep >= l)
		cnt = l;
	else
		cnt = min(n - 1, maxdep + (l - maxdep) / 2);
	cout << cnt + 1 << endl;
	//system("pause");
	return 0;
}