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

// int £º <=2^31 - 1
// -2 147 483 648 --- 2 147 483 647
// billion ,million, thousand. 

class Solution {
public:
	string numberToWords(int num) {
		if (num == 0) return "Zero";
		else return int2str(num).substr(1); //remove the " " at str[0]
	}
private:
	string int2str(int num)
	{
		if (num >= billion)
			return int2str(num / billion) + " Billion" + int2str(num%billion);
		if (num >= million)
			return int2str(num / million) + " Million" + int2str(num%million);
		if (num >= thousand)
			return int2str(num / thousand) + " Thousand" + int2str(num%thousand);
		if (num >= hundred)
			return int2str(num / hundred) + " Hundred" + int2str(num%hundred);
		if (num >= 20)
			return " " + up20[num / 10 - 2] + int2str(num % 10);
		if (num >= 1)
			return " " + blow20[num - 1];
		else return "";
	}
	string up20[8] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	string blow20[19] = { "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	const int billion = 1000000000, million = 1000000, thousand = 1000, hundred = 100;
};
int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}


