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

vector<int> ans;

void search(int x, vector<int> vec)
{
	if (x == 0)
	{
		ans = vec;
		return;
	}
	if ( (x-1)%2==0 &&(x - 1) / 2 >= 0)
	{
		vec.push_back(1);
		search((x - 1) / 2, vec);
		vec.pop_back();
	}
	if ( (x-2)%2==0 &&(x - 2) / 2 >= 0)
	{
		vec.push_back(2);
		search((x - 2) / 2, vec);
		vec.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	search(n, vec);
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
	cout << endl;
	//system("pause");
	return 0;
}