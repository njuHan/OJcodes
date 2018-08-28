/*
KMP：D.E.Knuth、J.H.Morris和V.R.Pratt

KMP算法要解决的问题就是在字符串（t）中的模式（p）定位问题。说简单点就是我们平时常说的关键字搜索。模式串就是关键字（接下来称它为p），如果它在一个主串（t）中出现，就返回它的具体位置，否则返回-1（常用手段）。
*/

int KMP(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
	int tlen = strlen(t), plen = strlen(p);
    // 不能写成：(i < t.length() && j < p.length()) ,注意 int 和 size_t比较时负数的情况
	while (i < tlen && j < plen)  
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
    }

    if (j == strlen(p))
       return i - j;
    else 
       return -1;
}

void getNext(char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < strlen(p)-1)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}
