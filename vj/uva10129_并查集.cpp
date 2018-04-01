#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int wordNum = 26;
int dgree[wordNum];
int n, t;
bool used[wordNum];

// 使用并查集判断连通性
int p[wordNum];
int findSet(int x)
{
	return p[x] == x ? x : p[x] = findSet(p[x]);
}

int main() {
	cin >> t;
	while (t-->0)
	{
		cin >> n;
		string str;
		
		memset(dgree, 0, sizeof(dgree));
		memset(used, 0, sizeof(used));
		//初始化并查集， 最大连通分量为字母个数26
		int cc = 26;
		for (int i = 0; i < wordNum; i++)
		{
			p[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int u = str[0] - 'a';
			int v = str[str.size() - 1] - 'a';
			
			dgree[u]++;
			dgree[v]--;
			used[u] = used[v] = 1;
			int s1 = findSet(u), s2 = findSet(v);
			if (s1 != s2)
			{
				p[s1] = s2; //合并两个集合
				cc--; // 连通分量减一
			}
		}
		
	
		vector<int> d;
		for (int i = 0; i < wordNum; i++)
		{
			if (used[i] == 0) cc--; //处理没有出现的字母 (结点)
			else if (dgree[i] != 0)
				d.push_back(dgree[i]); // 处理度数
		}


		bool flag1 = (d.empty() || (d.size() == 2 && (d[0] == -1 || d[0] == 1)));
		if (flag1 && cc==1)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");

	}
	return 0;
}
