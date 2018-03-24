#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

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