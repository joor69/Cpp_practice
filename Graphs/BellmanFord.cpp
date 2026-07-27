#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int v;
    int wt;
    
    Edge(int v,int wt)
    {
        this->v=v;
        this->wt=wt;
    }
};
//BELLMAN FORD IS USED WHEN THERE ARE NEGATIVE EDGES IN A GRAPH
void BellmanFord(int src,vector<vector<Edge>> &graph)
{
    vector<int> dist(graph.size(),INT_MAX);
    int V=graph.size();

    dist[src]=0;


    for(int i=0;i<V-1;i++)
    {
         bool updated=false;
        for(int u=0;u<V;u++)
        {
            if(dist[u]==INT_MAX) 
                continue;//skip u if u is unreachable
           
            vector<Edge> edge=graph[u];
            for(Edge e:edge)
            {
                
                if(dist[e.v]> dist[u]+e.wt)
                {
                    dist[e.v]=dist[u] + e.wt;
                    updated=true;
                }
            }
        }
        if(!updated)
            break;

    }

    for(int d:dist)
    {
        cout<<d<<" ";
    }
}

int main()
{
     vector<vector<Edge>> graph(6);
    
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    BellmanFord(0,graph);

    return 0;
}