#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

class Solution2 {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		int len = s.length();
		if (len < 4 || len>12) return ans;
		string seg[4];
		for (int a = 1; a <= 3 && a + 3 <= len; a++)
		{
			seg[0] = s.substr(0, a);
			if (stoi(seg[0])>255 || a > 1 && seg[0][0] == '0') break;
			for (int b = 1; b <= 3 && a + b + 2 <= len; b++)
			{
				seg[1] = s.substr(a, b);
				if (stoi(seg[1]) > 255 || b > 1 && seg[1][0] == '0') break;
				for (int c = 1; c <= 3 && a + b + c + 1 <= len; c++)
				{
					seg[2] = s.substr(a + b, c);
					if (stoi(seg[2]) > 255 || c > 1 && seg[2][0] == '0') break;
					seg[3] = s.substr(a + b + c);
					if (stoi(seg[3]) > 255 || seg[3].length() > 1 && seg[3][0] == '0') continue;
					ans.push_back(seg[0] + "." + seg[1] + "." + seg[2] + "." + seg[3]);
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.size();
		if (len < 4 || len>12) return ans;
		this->thisS = s;
		search("", 0, 0);
		return ans;
	}
private:
	vector<string> ans;
	string thisS;
	//str当前ip, idx: 起始：thisS[idx], cur: ip字节下标
	void search(string str, int idx, int cur)
	{
		if (idx >= thisS.size()) return;
		if (cur == 3)
		{
			string ss = thisS.substr(idx);
			int temp = atoi(ss.c_str());
			if (temp <= 255 && to_string(temp).size() == ss.size())
			{
				str = str + "." + ss;
				str.erase(str.begin()); //remove "."
				ans.push_back(str);
			}
			return;
		}
		for (int i = 1; i <= 3; i++)
		{
			string ss = thisS.substr(idx, i);
			int temp = atoi(ss.c_str());
			if (temp<=255 && to_string(temp).size()==i)
				search(str + "." + ss, idx + i, cur + 1);
		}
	}
};

int main()
{
	Solution solu;
	string s = "1111";
	vector<string> ans = solu.restoreIpAddresses(s);
	system("pause");
	return 0;
}