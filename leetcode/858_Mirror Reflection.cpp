class Solution {
public:
    int mirrorReflection(int p, int q) {
        // https://leetcode.com/problems/mirror-reflection/discuss/145378/C++-Solutions-0-ms(with-Image-Explain)
        // lcm = m*p = n*q
        int lcm = p*q/gcd(p,q);
        int m = lcm/p, n = lcm/q;
        return m&1 ? (n&1 ? 1 : 2) : 0;
    }
private:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a%b) : a;
    }
};