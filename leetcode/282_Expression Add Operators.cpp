class Solution {
public:
	vector<string> addOperators(string num, int target) {
		this->num = num; this->target = target;
		search(0, "", 0, 0);
		return ans;
	}
	vector<string> ans;
	string num;
	int target;
    //注意加减法 和 乘法 优先级不同
    // val：当前整个式子的值，用于加减法的左侧
    // lhs: 用于乘法 左侧的值
	void search(int cur, string exp, long val, long lhs)
	{
		if (cur == num.length()) { 
			if (val == target)	ans.emplace_back(exp); 
			return; 
		}
		for (int i = cur + 1; i <= num.length(); i++)
		{
			if (num[cur] == '0' && i - cur > 1) break; //不能有前导0
			long rhs = stol(num.substr(cur, i-cur));
			if (cur == 0) search(i, to_string(rhs), rhs, rhs);
			else
			{
				search(i, exp + "+" + to_string(rhs), val + rhs, rhs);
				search(i, exp + "-" + to_string(rhs), val + (-rhs), -rhs);
				search(i, exp + "*" + to_string(rhs), (val - lhs) + lhs*rhs, lhs*rhs);
			}
		}
	}
};