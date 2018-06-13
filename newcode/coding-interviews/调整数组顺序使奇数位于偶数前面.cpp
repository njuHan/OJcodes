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