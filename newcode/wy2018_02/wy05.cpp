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

int arr[200005];
int main()
{
	int x, f, d, p;
	cin >> x >> f >> d >> p;
	int day = 0;
	
	if (f*x >= d)
		day = d / x;
	else
	{
		day = f + (d - f*x) / (p + x);
	}
	
	
	cout << day;
	//system("pause");
	return 0;
}


