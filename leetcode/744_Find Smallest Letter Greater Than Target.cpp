

class Solution {
public:
	// upper bound
	char nextGreatestLetter(vector<char>& letters, char target) {
		int x = 0, y = letters.size();
		while (x<y)
		{
			int mid = x + (y - x) / 2;
			if (letters[mid] <= target) x = mid + 1;
			else y = mid;
		}
		return x == letters.size() ? letters[0] : letters[x];
	}
};