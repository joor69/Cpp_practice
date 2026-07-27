#include<bits/stdc++.h>
using namespace std;

class Graph{

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

    //TOPOSORT using DFS
    void topohelper(int src,vector<bool> &vis, stack<int> &s)
    {
        vis[src]=true;
        for(int neigh:l[src])
        {
            if(!vis[neigh])
            {
                topohelper(neigh,vis,s);
            }
        }
        s.push(src);
    }

    void topoSort()
    {
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                topohelper(i,vis,s);
        }

        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    //TOPOSORT using BFS(Kahns algo)
    void indegree(vector<int> &indgr)
    {
        for(int i=0;i<indgr.size();i++)
        {
            for(int neigh:l[i])
            {
                indgr[neigh]++;
            }
        }
    }


    void toposort2()
    {
        vector<int> indgr(V,0);
        queue<int> q;

        indegree(indgr);

        for(int i=0;i<indgr.size();i++)
        {
            if(indgr[i]==0)
            {
                q.push(i);

            }
        }

        while(!q.empty())
        {
            int curr=q.front();
            cout<<curr<<" ";
            list<int> neigh=l[curr];
            q.pop();
            for(int v:neigh)
            {
                indgr[v]--;
                if(indgr[v]==0)
                    q.push(v);
            }
            
        }
    }

};

int main()
{
    Graph g(6,false);

    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);

    g.topoSort();
    cout<<endl;
    g.toposort2();
    return 0;
}