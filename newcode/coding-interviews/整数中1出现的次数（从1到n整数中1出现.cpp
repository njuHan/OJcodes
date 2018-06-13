class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    int prefix = n, curbit, suffix = 0, m = 1, ans = 0;
		while (prefix>0)
		{
			curbit = prefix % 10;
			//利用+8 使得cubit>=2时进位+1
			ans += (prefix + 8) / 10 * m + (curbit == 1 ? suffix + 1 : 0);
			prefix /= 10;
			suffix += curbit*m;
			m *= 10;
		}
		return ans;
    }
};