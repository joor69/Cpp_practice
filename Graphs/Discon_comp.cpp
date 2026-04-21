#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    //For printing the disconnected components 
    void dfshelper(int u, vector<bool> &visited)
    {
        visited[u] = true;
        cout << u<<" ";
        for (int ele : l[u])
        {
            if (!visited[ele])
            {
                dfshelper(ele, visited);
            }
        }
    }

    void dfs()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfshelper(i,visited);
                cout<<endl;
            }
        }

    }
};

int main()
{
    Graph graph(13);
    graph.addedge(1, 6);
    graph.addedge(6, 4);
    graph.addedge(4, 3);
    graph.addedge(4, 9);
    graph.addedge(3, 8);
    graph.addedge(3, 7);

    graph.addedge(0, 2);
    graph.addedge(2, 5);

    graph.addedge(10,11);
    graph.addedge(11,12);
    graph.addedge(10,12);

    graph.dfs();
    return 0;
}