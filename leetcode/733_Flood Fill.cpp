#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
#include<numeric>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		m = image.size(), n = image[0].size();
		dfs(sr, sc, image[sr][sc], newColor, image);
		return image;
	}
private:
	int m, n;
	void dfs(int x, int y, int color, int newColor, vector<vector<int>>& image)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] == newColor || image[x][y]!=color) return;
		image[x][y] = newColor;
		for (int i = 0; i < 4; i++)
			dfs(x + dx[i], y + dy[i], color, newColor, image);
		
	}
};