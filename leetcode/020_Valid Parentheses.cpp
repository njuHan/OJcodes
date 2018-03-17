#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;


class Solution {
public:
	bool isValid(string s) {
		int len = s.size();
		if (len % 2) return false;
		stack<char> sk;
		map<char, char> charMap;
		charMap[')'] = '(';
		charMap[']'] = '[';
		charMap['}'] = '{';
		for (int i = 0; i < len; i++)
		{
			if (!charMap.count(s[i]))
				sk.push(s[i]);
			else
			{
				if (sk.empty()) return false;
				if (sk.top() != charMap[s[i]])
					return false;
				sk.pop();
			}

		}
		if (sk.empty()) return true;
		return false;
		
	}
	//不用map, 提高速度
	bool isValid(string s)
	{
		deque<int> stack;

		for (auto c : s) {
			switch (c) {
			case '(':
			case '[':
			case '{':
				stack.push_back(c);
				break;
			case ')':
				if (stack.empty() || stack.back() != '(') return false;
				stack.pop_back();
				break;
			case ']':
				if (stack.empty() || stack.back() != '[') return false;
				stack.pop_back();
				break;
			case '}':
				if (stack.empty() || stack.back() != '{') return false;
				stack.pop_back();
				break;
			}
		}

		return stack.empty();
	}
};

int main()
{
	Solution solu;
	bool ans = solu.isValid("){");
	cout << ans;
	system("pause");
	return 0;
}