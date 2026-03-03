#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool helper(int src, int dest, vector<bool> &visited)
    {
        list<int> neighbours = l[src];
        visited[src] = true;
        if(src==dest)
            return true;
        for (int ele : neighbours)
        {
            if (visited[ele] == false)
            {
                if(helper(ele, dest, visited))
                    return true;
            }
        }
        return false;
    }

    void HasPath(int src, int dest)
    {
        vector<bool> visited(V, false);
        if(helper(src, dest, visited))
            cout<<"true";
        else
            cout<<"false";
    }
};

int main()
{
    Graph graph(4);

    graph.addedge(1,2);
    graph.addedge(2,3);

    graph.HasPath(1,3);
    return 0;
}