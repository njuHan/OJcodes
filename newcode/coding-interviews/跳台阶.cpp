class Solution {
public:
    int jumpFloor(int number) {
        if (number < 1) return 0;
		if (number == 1) return 1;
		if (number == 2) return 2;
		int ans = 0, f_1 = 2, f_2 = 1;
		for (int i = 3; i <= number; i++)
		{
			ans = f_1 + f_2;
			f_2 = f_1;
			f_1 = ans;
		}
		return ans;
    }
};