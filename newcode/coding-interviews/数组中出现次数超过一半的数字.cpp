
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int cnt = 0, ans = 0;
        for (int num : numbers)
        {
            if (cnt==0) ans = num, cnt++;
            else if (ans==num) cnt++;
            else cnt--;
        }
        cnt = 0;
        for (int num : numbers) cnt += (num==ans);
        return cnt>numbers.size()/2 ? ans : 0;
    }
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		stack<int> sk;
		for (int num : numbers)
		{
			if (sk.empty()) sk.push(num);
			else
			{
				if (sk.top() != num) sk.pop();
				else sk.push(num);
			}
		}
		if (sk.empty()) return 0;
		int num = sk.top(), cnt = 0;
		for (int i = 0; i < numbers.size(); i++)
			if (numbers[i] == num) cnt++;
		return cnt * 2 > numbers.size() ? num : 0;
	}
};
