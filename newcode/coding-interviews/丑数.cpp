class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> mem;
		mem.push_back(1);
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < index; i++)
		{
			int next = min({ mem[p2] * 2, mem[p3] * 3, mem[p5] * 5 });
			mem.emplace_back(next);
			while (mem[p2] * 2 <= next) p2++;
			while (mem[p3] * 3 <= next) p3++;
			while (mem[p5] * 5 <= next) p5++;
		}
		return mem[index - 1];
    }
};