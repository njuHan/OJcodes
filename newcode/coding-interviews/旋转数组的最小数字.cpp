class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len < 1) return 0;
		int lo = 0, hi = len - 1;
		while (lo<hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (rotateArray[mid] < rotateArray[hi]) hi = mid;
			else if (rotateArray[mid] > rotateArray[hi]) lo = mid + 1;
			else hi--;
		}
		return rotateArray[lo];
	}
};