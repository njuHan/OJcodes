
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false

	// swap
	bool duplicate(int numbers[], int length, int* duplication)
	{
		if (length <= 1) return false;
		for (int i = 0; i < length; i++) if (numbers[i] < 0 || numbers[i] >= length) return false;
		for (int i = 0; i < length; i++)
		{
			while (numbers[i]!=i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				else swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}
	// 不能用 nums[idx] = -nums[idx], 因为 nums[idx]可能等于 0
	// 使用  nums[idx] += len
	bool duplicate_1(int numbers[], int length, int* duplication)
	{
		if (length <= 1) return false;
		for (int i = 0; i < length; i++) if (numbers[i] < 0 || numbers[i] >= length) return false;
		for (int i = 0; i < length; i++)
		{
			int idx = numbers[i] % length;
			if (numbers[idx] >= length)
			{
				*duplication = idx;
				return true;
			}
			else numbers[idx] += length;
		}
		return false;
	}

	//该题不保证有重复元素，所以leetcode287 快慢指针的方法不适用于这一题
	bool duplicate_2(int numbers[], int length, int* duplication) {
		int slow = 0, fast = 0, step = 0;
		do
		{
			if (step > length || fast >= length || slow >= length) return false;
			fast = numbers[numbers[fast]];
			slow = numbers[slow];
			step++;
			cout << fast << "," << slow << endl;
		} while (slow != fast);
		fast = 0;
		while (slow != fast)
		{
			slow = numbers[slow];
			fast = numbers[fast];
		}
		*duplication = fast;
		return true;
	}
};
int main()
{
	int nums[] = { 2,1,3,0,4 }, len = 5;
	Solution solu;
	int *p = new int;
	solu.duplicate(nums, len, p);
	system("pause");
	return 0;
}
