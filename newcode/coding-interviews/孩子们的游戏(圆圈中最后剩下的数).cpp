class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1) return -1;
        //n==1时， 只有一个 0号， last = 0
        // n==i-1时的 0 号， 对应与 n==i时的 m 号
        // 所以从 i-1 推到 i :  last = (last + m)%i
		//f(n,m) = (f(n-1,m) + m) % n;
		int last = 0;
		for (int i = 2; i <= n; i++)
		{
			last = (last + m) % i;
		}
		return last;
    }
};