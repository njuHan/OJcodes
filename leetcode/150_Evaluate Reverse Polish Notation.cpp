#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 0) return 0;
		int op1, op2;
		stack<int> sk;
		for (string token : tokens)
		{
			if (token.length() == 1 && !isdigit(token[0])) // token == "-11"
			{
				op2 = sk.top(); sk.pop();
				op1 = sk.top(); sk.pop();
				if (token == "+") sk.push(op1 + op2);
				else if (token == "-") sk.push(op1 - op2);
				else if (token == "*") sk.push(op1 * op2);
				else if (token == "/") sk.push(op1 / op2);
			}
			else
				sk.push(atoi(token.c_str()));

		}
		return sk.top();
	}
};

int main()
{
	Solution solu;
	vector<string> vec = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	solu.evalRPN(vec);

	return 0;
}