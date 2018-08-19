class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> isPrime(n, 1);
        for (long long  i=2; i<n; i++)
        {
            if (isPrime[i])
            {
                ans++;
                // 防溢出， 或者用 if (i > sqrt(n)) continue; 避免 i*i
                for (long long j = i*i ; j<n; j+=i)
                    isPrime[j] = 0;
            }
        }
        return ans;
    }
};