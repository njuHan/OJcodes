int d[] = {-1,1};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        dead = unordered_set<string>(deadends.begin(), deadends.end());
        vis.clear();
        queue<string> que;
        vis.insert("0000");
        if (!dead.count("0000")) que.push("0000");
        int cnt = 0;
        while (!que.empty())
        {
            int m = que.size();
            //cout<<endl<<cnt<<"--------"<<endl;
            while (m--)
            {
                string node = que.front(); que.pop();
                if (node==target) return cnt;
                for (int i=0; i<4; i++)
                    for (int j = 0; j<2; j++)
                    {
                        string next = node;
                        next[i] = (next[i]-'0' + d[j] + 10)%10 + '0';
                        if (!vis.count(next) && !dead.count(next))
                        {
                            vis.insert(next);
                            que.push(next);
                            //cout<<next<<",";
                        }
                    }
            }
            cnt++;
        }
        return -1;
    }
private:
    unordered_set<string> dead, vis;
};
