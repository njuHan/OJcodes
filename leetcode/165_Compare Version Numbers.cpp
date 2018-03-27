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

class Solution {
public:
	int compareVersion(string version1, string version2) {
		istringstream in1(version1);
		istringstream in2(version2);
		while (1)
		{
			int n1, n2;
			string s1, s2;
			if (!getline(in1, s1, '.')) n1 = 0;
			else n1 = atoi(s1.c_str());
			if (!getline(in2, s2, '.')) n2 = 0;
			else n2 = atoi(s2.c_str());
			if (!in1 && !in2 ) return 0; //in1, in2 读完之后在读就会变false
			else if (n1 < n2) return -1;
			else if (n1 > n2) return 1;
		}
	}
	int compareVersion2(string version1, string version2) {
		istringstream in1(version1);
		istringstream in2(version2);
		int num1=0, num2=0;
		char dot;
		
		while (1)
		{	
			in1 >> num1; in2 >> num2;
			if (!in1 && !in2) return 0;
			if (num1 < num2) return -1;
			else if (num1>num2) return 1;
			in1 >> dot; 
			in2 >> dot;
			num1 = num2 = 0;
		}
		return 0;

	}
};

int main()
{
	Solution solu;
	int ans = solu.compareVersion2("0.1", "0.001");
	system("pause");
	return 0;
}


