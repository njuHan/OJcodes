#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<bitset>
#include<map>
#include<sstream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
	string validIPAddress(string IP) {
		ans = { "IPv4", "IPv6", "Neither" };
		string temp = "0123456789abcdefABCEDF";
		set6 = unordered_set<char>(temp.begin(), temp.end());
		size_t isIPv4 = IP.find('.'), isIPv6 = IP.find(':');
		if ((isIPv4 == string::npos && isIPv6==string::npos) || (isIPv4 != string::npos && isIPv6 != string::npos))
			return ans[2];
		istringstream in(IP);
		string block;
		if (isIPv4 != string::npos)
		{
			for (int i = 0; i < 4; i++)
			{
				if (!getline(in, block, '.') || !isblock4(block))
					return ans[2];
			}
			return in.eof() ? ans[0] : ans[2]; //要考虑是否读完
		}
		else 
		{
			for (int i = 0; i < 8; i++)
			{
				if (!getline(in, block, ':') || !isblock6(block))
					return ans[2];
			}
			return in.eof() ? ans[1] : ans[2]; //要考虑是否读完
		}
	}
private:
	vector<string> ans;
	unordered_set<char> set6;
	bool isblock4(string block)
	{
		if (block.length() <= 0 || block.length()>3 || (block[0] == '0'&&block.length() > 1)) return false; // 前导0
		int num = 0;
		for (int i = 0; i < block.length(); i++)
		{
			if (!isdigit(block[i]) || (num = num * 10 + (block[i] - '0'))>255) return false;
		}
		return true;
	}
	bool isblock6(string block)
	{
		if (block.length() <= 0 || block.length()>4) return false;
		for (int i = 0; i < block.length(); i++)
		{
			if (!set6.count(block[i])) return false;
		}
		return true;
	}
	
};

int main()
{
	cout << string::npos;
	system("pause");
	return 0;
}