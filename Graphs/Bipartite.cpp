#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> * l;
    bool isUndir;

    public:

    Graph(int V,bool isUndir)
    {
        this->V=V;
        l=new list<int> [V];
        this->isUndir=isUndir;
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        if(isUndir)
            l[v].push_back(u);
    }

    //Detecting if the graph is Bipartie or not using BFS;
    //Fixing no need of visited array  as color array will act like visited array
    //Fixing the color of edges such that the src and its neighbors gets opposite color to each other

    bool helper (int src,vector<int>& color)
    {
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty())
        {
            int currele=q.front();
            q.pop();
            for(int neighbor:l[currele])
            {
                if(color[neighbor]==-1)
                {
                    color[neighbor]=1-color[currele];//does the flipping from 1 to 0 or 0 to 1
                    q.push(neighbor);
                }
                else if(color[neighbor]==color[currele])
                {
                        return false;
                }
                    
            }
        }

        return true;
    }

    bool isBipartite()
    {
        //vector<bool> visited(V,false);
        vector<int> color(V,-1);
        return helper(0,color);
    }


};

int main()
{
    Graph graph(5,true);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);

    cout<<graph.isBipartite();
    return 0;
}