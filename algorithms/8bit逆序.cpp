#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/reverse-bits/description/
unsigned char rev(unsigned char ch)
{
	unsigned char ans = 0;
	for (int i = 0; i < 8; i++)
	{
		ans = ans << 1;
		ans = ans | (ch & 1);
		ch = ch>> 1;
	}
	return ans;
}
unsigned char func(unsigned char c)
{
	c = (c & 0xaa) >> 1 | (c & 0x55) << 1;
	c = (c & 0xcc) >> 2 | (c & 0x33) << 2;
	c = (c & 0xf0) >> 4 | (c & 0x0f) << 4;

	return c;
}

int main()
{
	unsigned char ch = 0xf0;
	printf("%x", func(ch));
	system("pause");
	return 0;
}