// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long x = 1, y = (long long)n+1;
        while(x<y)
        {
            long long mid = x + (y-x)/2;
            if (isBadVersion(mid)) y = mid;
            else x = mid+1;
        }
        return x;
    }
};