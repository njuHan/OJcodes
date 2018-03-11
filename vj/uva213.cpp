#include<stdio.h>
#include<string.h>

int codes[8][1 << 8];

int readchar()
{
	int ch;
	while (1)
	{
		ch = getchar();
		if (ch != '\n' && ch != '\r')
			break;

	}
	return ch;
}

int readcodes()
{
	memset(codes, 0, sizeof(codes));
	codes[1][0] = readchar();
	for (int i = 2; i<8; i++)
		for (int j = 0; j < (1 << i) - 1; j++)
		{
			int ch = getchar();
			if (ch == EOF)
				return 0;
			if (ch == '\n' || ch == '\r')
				return 1;
			codes[i][j] = ch;
		}

}

int read_binary(int num)
{
	int n = 0;
	while (num--)
	{
		n = n * 2 + readchar() - '0';
	}
	return n;
}

void print_codes()
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < 1 << i; j++)
		{
			if (codes[i][j] == 0)
				break;
			//printf("len:%d, value:%d, code: %c, ", i, j, codes[i][j]);
		}
		//printf("\n");
	}
}

int main()
{
	
	//read header
	while (readcodes()) 
	{
		print_codes();
		while (1)
		{
			//read  length
			int len = read_binary(3);
			//("len = %d", len);
			if (len == 0)
				break;

			while (1)
			{
				int value = read_binary(len);
				//end if segment, a str of 1's
				if (value == (1 << len) - 1)
					break;
				//printf("%d,%d\n", len, value);
				printf("%c", codes[len][value]);

			}
		}
		printf("\n");
	}

	return 0;
}
