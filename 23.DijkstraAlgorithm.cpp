/*
 * This program constructs a graph from user inputs and
 * finds shortest path distances to everynode from node 0 using
 * Dijkstra's Shortest Path algorithm
 *
 *      Coded by: Abdurrezak Efe
 * */

#include <iostream>
using namespace std;

const int V = 1000; //assumed number of vertices
int edges[V+1][V+1] = {0}; //the graph itself

int minDistanceIndex(int distance[], bool inPath[], int v)
{
    int minDist = 999999999, minIndex=-1;

    for(int i=0; i<v; i++)
        if(!inPath[i] && distance[i] < minDist)
            minDist = distance[i], minIndex = i;

    return minIndex;
}

void Dijkstra( int v, int e)
{
    int distance[v];
    bool inPath[v];

    for(int i=0;i<v;i++)
        distance[i] = 999999999, inPath[i] = false;

    distance[0] = 0;

    int vertices = 0;
    while(vertices < v-1)
    {
        int u = minDistanceIndex(distance, inPath, v);

        inPath[u] = true;

        //operating on u's neighbors to add the smallest
        for(int i=0; i<v; i++)
            if( !inPath[i] && edges[u][i] && distance[u]+edges[u][i] < distance[i])
                distance[i] = distance[u]+edges[u][i];

        vertices++;
    }

    int i = 0;
    while(i<v)
        cout << "vertex: " <<i << ", distance: " <<  distance[i]  << endl, i++;
}

int main()
{
    int v,e;
    cin >> v >> e;

    //constructing the graph
    int x,y,w;
    for(int i=0;i<e;i++)
        cin >> x >> y >> w, edges[x][y] = edges[y][x] = w;

    Dijkstra(v, e);
}