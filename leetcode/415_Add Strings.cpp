#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1, j = num2.length()-1, carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry)
        {
            carry += (i>=0 ? num1[i--]-'0' : 0) + (j>=0 ? num2[j--]-'0' : 0);
            ans += carry%10 + '0';
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
	string addStrings(string num1, string num2) {
		int len1 = num1.length(), len2 = num2.length();
		if (len1 < len2) return addStrings(num2, num1);
		int i = len1 - 1, j = len2 - 1, carry = 0;
		for (; i >= 0 && (carry>0 || j >= 0); i--, j--)
		{
			if (num1[i] == '.') continue;
			carry += num1[i] - '0';
			if (j >= 0) carry += num2[j] - '0';
			num1[i] = carry % 10 + '0';
			carry /= 10;
		}
		return carry ? "1" + num1 : num1;
	}
	//带小数点的
	string addStrings2(string num1, string num2) {
		int len1 = num1.length(), len2 = num2.length();
		int pos1 = num1.find_first_of('.'), pos2 = num2.find_first_of('.');
		if (pos1 == string::npos && pos2 == string::npos) return addStrings(num1, num2);
		if (pos2 == string::npos) return addStrings(num1.substr(0, pos1), num2) + num1.substr(pos1);
		if (pos1 == string::npos) return addStrings(num1, num2.substr(0, pos2)) + num2.substr(pos2);
		int comLen = min(len1 - pos1, len2 - pos2) ;
		pos1 += comLen;
		pos2 += comLen;
		return addStrings(num1.substr(0, pos1), num2.substr(0, pos2)) + (pos1 == len1 ? num2.substr(pos2) : num1.substr(pos1));
	}
};

int main()
{
	string a = "1100.12345", b = "111.1";
	Solution solu;
	cout << solu.addStrings2(b, a);
	
	system("pause");
	return 0;
}