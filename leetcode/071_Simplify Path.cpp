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
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string path2(path);
		while (path2.find('/') != -1)
		{
			path2 = path2.replace(path2.find("/"), 1, " ");
		}
		istringstream strin(path2);
		string dir;
		vector<string> sk;
		while (strin >> dir)
		{
			if (dir == "..")
			{
				if (!sk.empty()) sk.pop_back();
			}
			else if (dir == ".");
			else
			{
				sk.push_back(dir);
			}
		}
		string ans;
		if (sk.size() == 0)
		{
			ans.push_back('/');
			return ans;
		}
		for (int i = 0; i < sk.size(); i++)
		{
			ans.push_back('/');
			ans += sk[i];
		}
		return ans;

	}
	// use getline
	string simplifyPath2(string path) 
	{
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
	}
};
int main()
{
	Solution solu;
	string ans = solu.simplifyPath("/a/./b/../../c/");
	system("pause");
	return 0;
}