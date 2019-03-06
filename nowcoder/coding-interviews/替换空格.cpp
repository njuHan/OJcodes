char rep[] = "%20";
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0) return;
		int p = 0, q, spaceCnt = 0;
		while (str[p])
		{
			if (str[p]==' ') spaceCnt++;
			p++;
		}
		q = p + spaceCnt * 2;
		while (p!=-1)
		{
			if (str[p] != ' ') str[q--] = str[p--];
			else
			{
				for (int i = 2; i >= 0; i--)
					str[q--] = rep[i];
				p--;
			}
		}
		return;
	}
	
};