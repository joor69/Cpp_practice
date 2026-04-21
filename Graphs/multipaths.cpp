#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    bool isUndir = true;

public:
    Graph(int V, bool isUndir)
    {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    // Adding edge for directed graph
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (isUndir)
            l[v].push_back(u);
    }

    void helper(int src, int dest, vector<bool> &visited, string &path)
    {
        if (src == dest)
        {
            cout << path << dest<<endl;
            return;
        }

        visited[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if(!visited[v])
                helper(v,dest,visited,path);
        }

       path= path.substr(0,path.size()-1);
        visited[src]=false;
    }

    void printpath(int src, int dest)
    {
        vector<bool> visited(V, false);
        string Path = "";
        helper(src, dest, visited, Path);
    }
};

int main()
{
    Graph g(6, false);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 0);

    g.printpath(5,1);

    return 0;
}