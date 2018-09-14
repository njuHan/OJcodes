class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size(), diff;
        if (n<=2) return 1;
        diff = 0;
        for (int i = 1; i<n; i++)
        {
            if (diff * (A[i] - A[i-1])<0) return 0;
            else if (A[i]-A[i-1]!=0) diff = A[i] - A[i-1];
        }
        return 1;
    }
};