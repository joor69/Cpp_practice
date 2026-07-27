#include <bits/stdc++.h>
using namespace std;
// Implementing Kruskal's algorithm to find the MST which uses Disjoint set Data Structure
// Undirected Graph
class Edge
{
public:
    int u, v, wt;

    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph
{
    int n;
    vector<Edge> edge;
    vector<int> parents;
    vector<int> rank;

public:
    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parents.push_back(i);
            rank.push_back(0);
        }
    }

    // Disjoint Set DS;
    int find(int x)
    {
        if (parents[x] == x)
            return x;

        return parents[x] = find(parents[x]);
    }

    void unionByRank(int u, int v)
    {
        int parU = find(u);
        int parV = find(v);

        if (rank[parU] == rank[parV])
        {
            parents[parV] = parU;
            rank[parU]++;
        }
        else if (rank[parU] < rank[parV])
        {
            parents[parU] = parV;
        }
        else
        {
            parents[parV] = parU;
        }
    }


     void addEdge(int u, int v, int wt)
    {
        for (int i = 0; i < n; i++)
        {
            edge.push_back(Edge(u, v, wt));
        }
    }

    void Kruskals()
    {
        int minCost = 0;
        sort(edge.begin(), edge.end(), [](Edge &a, Edge &b)
             { return a.wt < b.wt; });

        for (int i = 0; i < edge.size(); i++)
        {
            Edge e = edge[i];
            int parU = find(e.u);
            int parV =find(e.v);

            if (parU != parV) // Detecting Cycle;
            {
                unionByRank(e.u,e.v);
                minCost += e.wt;
            }
        }

        cout << "Minimum Spanning tree Cost: " << minCost;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 20);
    g.addEdge(1, 2, 15);
    g.addEdge(1, 3, 30);
    g.addEdge(2, 3, 40);

    g.Kruskals();
    return 0;
}