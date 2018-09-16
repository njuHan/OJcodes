class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        color = vector<int>(N+1, 0);
        graph = vector<vector<int>>(N+1);
        for (auto& vec : dislikes)
        {   // undirected graph
            graph[vec[0]].emplace_back(vec[1]);
            graph[vec[1]].emplace_back(vec[0]);

        }
        for (int u=1; u <=N; u++)
            if (color[u]==0 && dfs(u,1)==false) return false;
        return true;
    }
private:
    vector<int> color;
    vector<vector<int>> graph;
    bool dfs(int u, int c)
    {
        color[u] = c;
        for (int v : graph[u])
        {
            if (color[v]==c || (color[v]==0&&dfs(v, -c)==false)) return false;
        }
        return true;
    }
};
