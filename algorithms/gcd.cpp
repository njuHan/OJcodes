#include<stdio.h>
#include<iostream>
struct test
{
	unsigned char a : 4;
	unsigned char b : 4;
};

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a%b));
}


