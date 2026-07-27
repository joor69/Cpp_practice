#include<iostream>
#include<queue>
#include<vector>
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

void dijkstra(int src,vector<vector<Edge>> &graph)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    vector<int> dist(graph.size(),INT_MAX);

    dist[src]=0;
    p.push(make_pair(0,src));

    while(p.size()>0)
    {
        int u=p.top().second;
        p.pop();

        vector<Edge> edge=graph[u];
        for(Edge e: edge)
        {
            if(dist[e.v]> dist[u]+e.wt)
            {
                dist[e.v]=dist[u]+e.wt;
                p.push(make_pair(dist[e.v],e.v));
            }
        }
    }

    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"----"<<dist[i]<<endl;
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


    dijkstra(2,graph);
    return 0;
}