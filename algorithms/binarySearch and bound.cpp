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

//[x,y)
int binarySearch(int* a, int x, int y, int v)
{
	int m;
	while (x<y)
	{
		m = x + (y - x) / 2;
		if (a[m] == v) return m;
		if (a[m] < v) x = m + 1;
		else y = m;
	}
	return -1;
}

int lower_bound(int* a, int x, int y, int v)
{
	int m;
	while (x<y)
	{
		m = x + (y - x) / 2;
		if (a[m] >= v) y = m;
		else x = m + 1;
	}
	return x;
}

int upper_bound(int* a, int x, int y, int v)
{
	int m;
	while (x<y)
	{
		m = x + (y - x) / 2;
		if (a[m] <= v) x = m + 1;
		else y = m;
	}
	return x;
}

int main()
{
	int a[] = { 1,3,5,7,9,2,4,6,8,10 };
	int n = 10;
	int v = 11;
	cout << lower_bound(a, 0, n, v) << endl;
	cout << upper_bound(a, 0, n, v) << endl;

	system("pause");
	return 0;
}



