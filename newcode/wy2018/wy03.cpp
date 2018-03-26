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
	vector<string> st;
	while (true)
	{
		char cur = str[0];
		int j = str.find_first_not_of(cur);
		if (j == -1)
		{
			st.emplace_back(str);
			break;
		}
		int len = j;
		st.emplace_back(str.substr(0, len));
		str = string(&str[j]);
	}
	double ans = 0;
	for (auto e : st)
		ans += e.size();
	printf("%.2lf\n", ans / st.size());
	//system("pause");
	return 0;
}