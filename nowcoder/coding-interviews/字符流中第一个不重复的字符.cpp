#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;
class Solution
{
public:
	Solution() : idx(0) {}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (cnt.count(ch)) cnt[ch] = -1;
		else cnt[ch] = idx++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int minidx = idx;
		char ans = '#';
		for (auto e : cnt)
			if (e.second >= 0 && e.second < minidx)
			{
				minidx = e.second;
				ans = e.first;
			}
		return ans;
	}
private:
	unordered_map<char, int> cnt;
	int idx;
};

int main()
{
	//remove char of "aeiou"
	string str("Please, replace the vowels in this sentence by asterisks.");
	size_t found = str.find_first_of("aeiou");
	while (found != string::npos)
	{
		str.erase(found, 1);
		found = str.find_first_of("aeiou", found);
	}

	cout << str << '\n';
	system("pause");
	return 0;
}