class Solution {
public:
     int  NumberOf1(int n) {
         int ans = 0;
		while (n)
		{
			ans++;
			n = n&(n - 1);
		}
		return ans;
     }
};