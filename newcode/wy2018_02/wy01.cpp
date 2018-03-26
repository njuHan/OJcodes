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
	string str;
	cin >> str;
	set<char> st;
	for (auto e : str)
		st.insert(e);
	if (st.size() > 2)
		cout << "0";
	else
		cout << st.size();
	//system("pause");
	return 0;
}


