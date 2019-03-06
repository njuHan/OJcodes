class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n = pushV.size();
		if (n != popV.size()) return false;
		stack<int> sk;
		int i = 0, j = 0;
		while (j<n)
		{
			while (i<n && (sk.empty() || sk.top()!=popV[j])) sk.push(pushV[i++]);
            if (sk.top()==popV[j]) j++, sk.pop();
            else return false;
		}
		return true;
    }
};