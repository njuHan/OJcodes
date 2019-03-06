class Solution {
public:
    int rectCover(int number) {
       if (number < 1) return 0;
		if (number == 1) return 1;
		if (number == 2) return 2;
		int n_1 = 2, n_2 = 1, ans;
		for (int i = 3; i <= number; i++)
		{
			ans = n_1 + n_2;
			n_2 = n_1;
			n_1 = ans;
		}
		return ans;
    }
};