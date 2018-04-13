#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		string sk;
		for (char ch : s)
		{
			if (ch == ']')
			{
				string encodeStr = "";
				string k = "";
				while (sk.back()!='[')
				{
					encodeStr = sk.back() + encodeStr;
					sk.pop_back();
				}
				sk.pop_back();
				while (isdigit(sk.back()))
				{
					k = sk.back() + k;
					sk.pop_back();
				}
				int repeat = stoi(k);
				for (int i = 0; i < repeat; i++)
					for (int j = 0; j < encodeStr.size(); j++)
						sk.push_back(encodeStr[j]);

			}
			else
				sk.push_back(ch);
		}
		return sk;
	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}



