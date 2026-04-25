#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    // Adding bool isUndir to check directed vs undirected
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

    // detecting cycle code

    bool helper(int src, vector<bool> &visited, vector<bool> &recPath)
    {
        visited[src] = true;
        recPath[src] = true;
        for (int ele : l[src])
        {
            if (!visited[ele])
            {
                if (helper(ele, visited, recPath))
                    return true;
            }
            else
            {
                if (recPath[ele])
                    return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir()
    {
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            // FIX: Only start DFS if node haven't been visited yet
            if (!visited[i])
            {
                if (helper(i, visited, recPath))
                    return true;
            }
        }

        return false;
    }

    //Kahn's algorithm to detect cycle

    void calcindegree(vector<int> &indgr)
    {
        for(int i=0;i<indgr.size();i++)
        {
            for(int neigh:l[i])
            {
                indgr[neigh]++;
            }
        }
    }

    bool isCycle()
    {
        vector<int> indgr(V,0);
        queue<int> q;

        calcindegree(indgr);
        for(int i=0;i<V;i++)
        {
            if(indgr[i]==0)
                q.push(i);
        }


        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int neigh:l[curr])
            {
                if(indgr[neigh]==0)
                    q.push(neigh);
                else
                    indgr[neigh]--;
            }
 
        }

        for(int i=0;i<indgr.size();i++)
        {
            if(indgr[i]!=0)
                return true;
        }
        
        return false;

    }


};





int main()
{
    Graph graph(5, false);

    graph.addEdge(0, 1);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 2);

    // OUTPUT AS 0 FOR FALSE & 1 FOR TRUE
    //cout << graph.isCycleDir();
    cout<<graph.isCycle();
    return 0;
}