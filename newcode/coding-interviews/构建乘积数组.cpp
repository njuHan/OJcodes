class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
		if (len < 2) return{};
		vector<int> B(len, 1);
		int left = 1, right = 1;
        for (int i=0; i<len; i++)
        {
            B[i] *= left;
            B[len-1-i] *= right;
            left *= A[i];
            right *= A[len-1-i];
        }
		return B;
    }
};

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		if (len < 2) return{};
		vector<int> B(len, 1);
		for (int i = 1; i < len; i++)
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		int temp = 1;
		for (int i = len - 2; i >= 0; i--)
		{
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};