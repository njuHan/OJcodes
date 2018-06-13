class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int n = sequence.size(); 
        if (n == 0) return false;
		nums = sequence;
		return isValid(0, n - 1);
	}
private:
	vector<int> nums;
	//[x,y]
	bool isValid(int x, int y)
	{
		if (y - x + 1 <= 1) return true;
		int root = nums[y], i=0, j;
		while (i < y && nums[i] < root) i++;
		for (j = i; j < y; j++)
			if (nums[j] < root) return false;
		return isValid(x, i - 1) && isValid(i, y - 1);
	}

};