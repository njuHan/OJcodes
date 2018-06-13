class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0 || base == 1) return 1;
		if (exponent < 0) return 1/base * Power(1 / base, -(exponent+1));
		return exponent % 2 ? base*Power(base*base, exponent / 2) : Power(base*base, exponent / 2);
	}
};