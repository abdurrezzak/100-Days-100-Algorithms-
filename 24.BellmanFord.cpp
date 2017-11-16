/*
 *  This program constructs a graph from user inputs and
 *  find a single source shortest path using
 *  Ballman-Ford algorithm
 *
 *      Coded by: Abdurrezak Efe
 *
 * */

#include <iostream>
#include <vector>
using namespace std;
typedef pair< int , int> edge;

//constructing the graph
class Graph{

public:

    vector <pair<int , edge >> edges;
    int v;
    int e;

    Graph(int v, int e)
    {
        //edges.resize(e);
        this->v = v;
        this->e = e;
    }

    void add_edge(int x, int y, int w)
    {
        edge ee = {x,y};
        pair<int, edge> newedge= {w, ee};
        edges.push_back(newedge);
    }

};


bool bellman_ford(Graph g)
{
    //initializing arrays
    int distance[g.v];
    int previous[g.v];

    for(int i=0;i<g.v;i++)
        distance[i] = 999999999, previous[i] = -1;

    distance[0] = 0;

    //updating the distance in every step
    for(int i=0;i<g.v-1;i++)
    {
        for(int j=0;j<g.edges.size();j++)
        {
            int u,v,w;
            u = g.edges[j].second.first;
            v = g.edges[j].second.second;
            w = g.edges[j].first;
            if(distance[u] + w < distance[v] )
                distance[v] = distance[u] + w, previous[v] = u;
        }
    }

    //checking negative weight cycles
    for(int j=0;j<g.edges.size();j++)
    {
        int u,v,w;
        u = g.edges[j].second.first;
        v = g.edges[j].second.second;
        w = g.edges[j].first;
        if(distance[u] + w < distance[v] )
        {
            cout << "Negative cycle detected! " << endl;
            return false;
        }
    }


    for(int i=0;i<g.v;i++)
        cout << "vertex: "<< i << " distance: " << distance[i] << " parent: " << previous[i] << endl;


    return 1;
}


int main()
{
    int v,e;
    cin >> v >> e;

    Graph g(v,e);

    int x,y,w;
    for(int i=0;i<e;i++)
    {
        cin >> x >> y >> w;
        g.add_edge(x,y,w);
    }

    bellman_ford(g);
}