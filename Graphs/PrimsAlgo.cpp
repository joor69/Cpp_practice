#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir)
    {
        this->V = V;
        this->isUndir = isUndir;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back(make_pair(v, wt));
        if (isUndir)
            l[v].push_back(make_pair(u, wt));
    }
    //finding MST using Prims's Algorithm;
    void MST()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        vector<bool> vis(V, false);

        int src = 0, ans = 0;
        p.push(make_pair(0, src)); // pair(weigh,dest)

        while (p.size() > 0)
        {
            int u = p.top().second;
            int cost = p.top().first;
            p.pop();


            if (!vis[u])
            {
                vis[u]=true;
                ans+=cost;
                list<pair<int, int>> neigh = l[u];
                for (pair<int, int> pp : neigh)
                {
                    p.push(make_pair(pp.second, pp.first));
                }
            }
        }

        cout << ans << endl;
    }
};

int main()
{
    int V = 4;

    Graph g(4, true);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 20);
    g.addEdge(3, 2, 50);
    g.addEdge(0, 3, 30);
    g.addEdge(0, 2, 15);

    g.MST();
    return 0;
}