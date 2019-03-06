class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 1) return 1;
        int f0 = 1, f1 = 1, ans;
        for (int i=2; i<=number; i++)
        {
            ans = f0 + f1;
            f0 = f1;
            f1 = ans;
        }
        return ans;
    }
};

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