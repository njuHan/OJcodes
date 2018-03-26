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
using namespace std;




int main()
{
	int t, n;
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		int num;
		int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num; 
			num = num % 4;
			if (num == 0) cnt0++;
			else if (num == 1) cnt1++;
			else if (num == 2) cnt2++;
			else cnt3++;
		}
		int odd = cnt2 % 2 + cnt1 + cnt3;
		if (cnt0 >= odd - 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	system("pause");
	return 0;
}