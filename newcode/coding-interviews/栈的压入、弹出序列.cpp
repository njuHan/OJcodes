class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len1 = pushV.size(), len2 = popV.size();
		if (len1 != len2) return false;
		stack<int> sk;
		int i = 0, j = 0;
		while (i<len1)
		{
			if (j == len1)
			{
				if (popV[i] == sk.top())
				{
					i++;
					sk.pop();
				}
				else
					return false;
			}
			else
			{
				if (popV[i] == pushV[j])
				{
					i++;
					j++;
				}
				else sk.push(pushV[j++]);
			}
		}
		return true;
    }
};