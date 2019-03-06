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
using namespace std;



int main()
{
	string str;
	cin >> str;
	string rstr(str.rbegin(), str.rend());
	long long ans = atoi(str.c_str()) + atoi(rstr.c_str());
	cout << ans << endl;
	//system("pause");
	return 0;
}