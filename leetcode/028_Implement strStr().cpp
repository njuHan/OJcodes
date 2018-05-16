#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		t = haystack;
		p = needle;
		int tlen = haystack.length(), plen = needle.length();
		if (plen == 0) return 0;
		next = vector<int>(plen, 0);
		getNext();
		int i = 0, j = 0;
		while (i < tlen && j < plen)  // 不能写成：(i < t.length() && j < p.length()) ,注意 int 和 size_t比较时负数的情况
		{
			if (j == -1 || t[i] == p[j])
			{
				i++;
				j++;
			}
			else
				j = next[j];
		}
		if (j == p.length())
			return i - j;
		else
			return -1;
	}
private:
	string t;
	string p;
	vector<int> next;
	void getNext()
	{
		next[0] = -1; 
		int i = 0, j = -1;
		while (i<p.length()-1)
		{
			if (j == -1 || p[i] == p[j])
			{
				next[++i] = ++j;
			}
			else
				j = next[j];
		}
	}
};
int main()
{
	char str[] = "12";
	char* p = str;
	size_t a = 2;

	int b = -4;
	for (; b < 4; b++)
	{
		cout << "b = " << b << ", " << "b<a = " << (b < strlen(p)) << endl;
	}
	system("pause");
	return 0;
}