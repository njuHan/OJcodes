#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		istringstream in(s);
		string last;
		while (in >> last);
		return last.size();
	}
};

int main()
{
	Solution solu;
	solu.lengthOfLastWord("1 2 3 4 5 6 7");
	system("pause");
	return 0;
}