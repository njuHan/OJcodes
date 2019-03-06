#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>

using namespace std;

int dp[15][100005];

//dp[i][j]表示整个状态空间，其中i(1 <= i <= n)表示数列的长度，j(1 <= j <= k)表示数列长度为i且以数字j结尾。合法序列的个数
//递推关系有：dp[i][j] += dp[i - 1][m](1 <= m <= k, 并且(m, j)是个合法的数列)，
//但是直接按照递推关系，用三层for循环会超时。为此可以先将长度为i - 1的合法数列求和(记为sum)。
//然后对于数列长度为i的每一个j，求出数列长度为i - 1时非法的序列个数（记为invalid）, 即有dp[i][j] = sum - invalid。
//对于invalid求取，可以参照素数筛选。算法的时间复杂度大概为O(nkloglogk)

//对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
// dp[i][j] += dp[i - 1][m] 相当于m后面添加j,
//所以判断非法时，只需考虑 m>j && m%j==0; 即： m = p*j (p>=2)

const int mod = 1000000007;
int main()
{
	int n, k;
	cin >> n >> k;
	//初始化 dp[1][j] = 1;
	for (int j = 1; j <= k; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= n; i++)
	{
		int sum = 0; //求和长度为 i-1的合法序列的个数
		for (int j = 1; j <= k; j++)
			sum = (sum + dp[i - 1][j])%mod;
		//求 dp[i][j]
		for (int j = 1; j <= k; j++)
		{
			//invalid: dp[i-1][p*j] (p>=2)
			int invalid = 0;
			int p = 2;
			while (p*j <= k)
			{
				invalid = (invalid + dp[i - 1][p*j]) % mod;
				p++;
			}
			dp[i][j] = (sum - invalid + mod) % mod; //小心负数
		}
	}
	int sum = 0;
	// sum dp[n][i]
	for (int i = 1; i <= k; i++)
		sum = (sum + dp[n][i]) % mod;
	cout << sum;
	system("pause");
	return 0;
}


