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

class Solution {
public:
	bool isNumeric(char* string)
	{
		int len = strlen(string), i = 0;
		if (len < 1) return false;
		//skip the leading spaces
		while (i < len && string[i] == ' ') i++;
		//skip sign
		if (string[i] == '+' || string[i] == '-') i++;
		//check significant part
		int digitCnt = 0, dotCnt = 0;
		while (i<len && (isdigit(string[i])||string[i]=='.'))
		{
			if (isdigit(string[i])) digitCnt++;
			else dotCnt++;
			if (dotCnt > 1) return false;
			i++;
		}
		if (digitCnt < 1) return false;
		//check exp part
		if (i < len && (string[i] == 'e' || string[i] == 'E'))
		{
			i++;
			if (i == len) return false;
			if (string[i] == '+' || string[i] == '-') i++;
			digitCnt = 0;
			while (i<len && isdigit(string[i])) 
			{
				digitCnt++;
				i++;
			}
			if (digitCnt < 1) return false;
			
		}

		//skip trailing spaces
		while (i < len && string[i] == ' ') i++;
		return i == len;

	}

};

int main()
{
	Solution solu;
	solu.isNumeric("0");
}