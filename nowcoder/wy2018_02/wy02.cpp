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
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << "Possible" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	int diff = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
	{
		if (arr[i] - arr[i - 1] != diff)
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	system("pause");
	return 0;
}


