class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        if (n<1) return 0;
        int ans = array[0], acc = array[0];
        for (int i=1; i<n; i++)
        {
            if (acc>0) acc += array[i];
            else acc = array[i];
            ans = max(ans, acc);
        }
        return ans;
    }
};
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int len = array.size();
		int pre = array[0], cur , maxsum = array[0];
		for (int i = 1; i < len; i++)
		{
			cur = array[i] + max(0, pre);
			maxsum = max(maxsum, cur);
			pre = cur;
		}
		return maxsum;
	}
};

