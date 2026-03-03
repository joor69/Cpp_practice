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


    void print()
    {
        for(int u=0;u<V;u++)
        {
            list<int> neighbours=l[u];
            cout<<u<<"---";
            for(int ele:neighbours)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph graph(5);
    graph.addedge(0,1);
    graph.addedge(1,2);
    graph.addedge(1,3);
    graph.addedge(2,3);
    graph.addedge(2,4);


    graph.print();

    return 0;
}

