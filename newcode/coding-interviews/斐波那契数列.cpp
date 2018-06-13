int cache[40] = {0};
class Solution {
public:
	int Fibonacci(int n) {
		if (n < 1) return 0;
		if (n == 1 || n == 2) return 1;
		int f1 = 1, f2 = 1, ans;
		for (int i = 3; i <= n; i++)
		{
			ans = f2 + f1;
			f1 = f2;
			f2 = ans;
		}
		return ans;
	}
};