class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int n = array.size();
		// 冒泡排序的思想，注意按位与 & 的优先级小于 == ，要加括号
		for (int k = n-1; k >= 0; k--)
		{
			if ( (array[k]&1) == 0)
			{
				for (int i = k, j = k + 1; j < n && (array[j] & 1); i++, j++)
					swap(array[i], array[j]);
			}
		}
	}
};

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
		if (len <= 1) return;
		for (int i = len - 1; i >= 0; i--)
		{
			if (array[i] % 2) continue;
			int j = i + 1;
			while (j<len && array[j]%2)
			{
				swap(array[j - 1], array[j]);
				j++;
			}
		}
    }
};