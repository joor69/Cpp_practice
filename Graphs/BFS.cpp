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

    void print()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbours = l[u];
            cout << u << "---";
            for (int ele : neighbours)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    //BFS O(V+E)
    void bfs(int v)
    {
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(v);
        visited[v] = true;

        while (!q.empty())
        {
            int u = q.front();
            cout<<u<<" ";
            q.pop();
            list<int> neighbours = l[u];
            for (int ele : neighbours)
            {
                if (visited[ele] == false)
                {
                    q.push(ele);
                    visited[ele] = true;
                }
            }
        }
        cout<<endl;
    }

    ///DFS O(V+E)

    void dfshelper(int v,vector<bool> & visited)
    {
        visited[v]=true;
        cout<<v<<" ";

        list<int> neighbours=l[v];
        for(int ele:neighbours)
        {
            if(visited[ele]!=true)
            {
                dfshelper(ele,visited);
            }
        }

    }


    void dfs(int v)
    {
        vector<bool> visited(V,false);
        dfshelper(v,visited);
        cout<<endl;
    }
};

int main()
{
    Graph graph(7);
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(3, 4);
    graph.addedge(3, 5);
    graph.addedge(5,6);


    //graph.print();
    graph.bfs(0);
    graph.dfs(0);

    return 0;
}
