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

//将原数列排好序，每次取数列中的最大与最小值加入到疯狂队列中（想象一下疯狂队列从中间向两边扩展），
//与上一次加入的最小与最大值交叉做差，直到原数列中仅剩最后一个值，把它放到疯狂队列合适的位置上保证疯狂值最大即可。
const int maxn = 55;
int arr[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n <= 1)
	{
		cout << 0;
		return 0;
	}
	sort(&arr[0], &arr[n]);
	int maxnum = arr[n - 1];
	int minnum = arr[0];
	int ans = maxnum - minnum;
	int minidx = 1, maxidx = n - 2;
	while (minidx < maxidx)
	{
		ans += maxnum - arr[minidx];
		ans += arr[maxidx] - minnum;
		maxnum = arr[maxidx--];
		minnum = arr[minidx++];
	}
	if (n % 2) ans += max(maxnum - arr[minidx], arr[minidx] - minnum);
	cout << ans;
	//system("pause");
	return 0;
}


