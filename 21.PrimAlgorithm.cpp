/*
 * This program constructs an undirected graph by taking edges and vertices from the user
 * and sing Prim's Algorithm
 * constructs a Minimum Spanning Tree
 *
 *      Coded by: Abdurrezak Efe
 * */

#include <iostream>
#include <limits.h>
using namespace std;

const int V = 1000; //assumed number of vertices
int edges[V+1][V+1] = {0}; //the graph itself

int minKeyIndex(int keys[], bool inMST[], int v) //finding the minimum keyed vertex
{
    //finding the vertex with smallest key to add to MST
    int minKey = INT_MAX, minIndex=-1;
    for(int i=0; i<v; i++)
        if(!inMST[i] && keys[i] < minKey)
            minKey = keys[i], minIndex = i;

    return minIndex;
}

void Prim( int v, int e)
{
    int keys[v];
    int previous[v];
    bool inMST[v];

    for(int i=0;i<v;i++)
        keys[i] = INT_MAX, inMST[i] = false;

    keys[0] = 0;
    previous[0] = -1;

    int vertices = 0;
    while(vertices < v-1) //there will be v vertices in MST
    {

        int u = minKeyIndex(keys, inMST, v);

        //adding u to MST
        inMST[u] = true;

        //operating on u's neighbors to add the smallest
        for(int i=0; i<v; i++)
            if(edges[u][i] && !inMST[i] && edges[u][i] < keys[i])
                previous[i] = u, keys[i] = edges[u][i];

        vertices++;
    }


    //printing MST
    int i = 1;
    while(i<v)
        cout << i << ", " <<  previous[i] << ", " << edges[i][previous[i]] << endl, i++;

}

// driver program to test above function
int main()
{
    int v,e;
    cin >> v >> e;

    //constructing the graph
    int x,y,w;
    for(int i=0;i<e;i++)
        cin >> x >> y >> w, edges[x][y] = edges[y][x] = w;

    Prim(v, e);
}