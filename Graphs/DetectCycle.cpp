#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> * l;
    public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int> [V];
    }

    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleHelper(int src,int par,vector<bool>&visit)
    {
        visit[src]=true;
        for(int neigh:l[src])
        {
            if(!visit[neigh])
            {
                if(isCycleHelper(neigh,src,visit))
                    return true;
            }
            else
            {
                if(neigh!=par)
                    return true;
            }
        }

        return false;
    }

    bool isCycle()
    {
        vector<bool> visit(V,false);
        return isCycleHelper(0,-1,visit);
    }

};

int main()
{
    Graph graph(3);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(1,2);

    cout<<graph.isCycle();
    return 0;
}