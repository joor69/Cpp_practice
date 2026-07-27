#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    public:

    int v;
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int v)
    {
        this->v=v;
        for (int i = 0; i <v; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
        
    }

    int find(int x)
    {
        if(parent[x]==x)
            return x;
        
        return parent[x]=find(parent[x]);//Path compression where the parent becomes the leader of the set;
    }
    

    void unionByRank(int a,int b)
    {
        int parA=find(a);
        int parB=find(b);

        if(rank[parA]==rank[parB])
        {
            parent[parB]=parent[parA];
            rank[parA]++;
        }
        else if(rank[parA]>rank[parB])
        {
            parent[parB]=parA;
        }
        else
        {
            parent[parA]=parB;
        }
    }

    void getInfo()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" rank-"<<rank[i]<<" parent-"<<parent[i]<<endl;
        }
    }
};

int main()
{
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    dj.unionByRank(0,4);

    dj.getInfo();
    return 0;
}