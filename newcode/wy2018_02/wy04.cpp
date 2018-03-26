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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int i = n - 1;
	cout << arr[i];
	i -= 2;
	while (i >= 0)
	{
		cout <<" " <<arr[i] ;
		i -= 2;
	}
	int j = i == -2 ? 1 : 0;
	while (j < n)
	{
		cout << " "<<arr[j];
		j += 2;
	}
	//system("pause");
	return 0;
}


