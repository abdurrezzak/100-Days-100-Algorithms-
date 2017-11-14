/*
 *  This function takes a graph from the user and finds a minimum
 *  spanning tree using
 *  Kruskal's Algorithm
 *
 *      Coded by: Abdurrezak Efe
 *
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair< int , int> edge;

class Graph{

public:

    vector <pair<int , edge >> edges;
    int v;

    Graph(int v, int e)
    {
        //edges.resize(e);
        this->v = v;
    }

    void add_edge(int x, int y, int w)
    {
        edge ee = {x,y};
        pair<int, edge> newedge= {w, ee};
        edges.push_back(newedge);
    }

};

//function to what set a vertex belongs to
int find_parent(int x, int par[])
{
    if(par[x] == x)
        return x;
    return  par[x] = find_parent(par[x], par);
}

void Kruskal(Graph g)
{
    int par[g.v+1];
    for(int i=0;i<g.v+1;i++)
        par[i] = i;

    //sorting edges acoording to their weights
    sort(g.edges.begin(),g.edges.end());

    vector<pair<int,int>> mst;

    for(int i=0;i<g.edges.size();i++)
    {
        int u,v;
        u = g.edges[i].second.first;
        v = g.edges[i].second.second;

        if(find_parent(u, par) != find_parent(v, par))
        {
            mst.push_back(g.edges[i].second);
            par[find_parent(v, par)] = find_parent(u, par);
        }
    }

    for(int i=0;i<mst.size();i++)
        cout << mst[i].first << " " << mst[i].second << endl;
}

int main()
{
    int v,e;
    cin >> v >> e;

    //constructing the graph
    Graph g(v,e);
    int x,y,w;
    for(int i=0;i<e;i++)
        cin >> x >> y >> w, g.add_edge(x,y,w);

    Kruskal(g);
}