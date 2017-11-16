/*
 *  This program constructs a graph from user inputs and
 *  computes all pairs shortest paths between every pair of nodes using
 *  Floyd Warshall Algorithm
 *
 *      Coded by: Abdurrezak Efe
 * */

#include <iostream>
#include <limits.h>
using namespace std;

const int V = 1000; //assumed number of vertices
int edges[V+1][V+1] = {0}; //the graph itself

void floyd_warshall(int v)
{
    int distance[v+1][v+1];


    //initializing distance matrix
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            distance[i][j] = edges[i][j];


    //updating distance
    for(int k=0;k<v;k++)
        for(int j=0;j<v;j++)
            for(int i=0;i<v;i++)
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);

    //printing shortest ways between nodes
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout << distance[i][j] << " ";
        cout << endl;
    }
}

// driver program to test above function
int main()
{

    int v,e;
    cin >> v >> e;

    for(int i=0;i<v+1;i++)
        for(int j=0;j<v+1;j++)
            if(i != j)
                edges[i][j] = 999999999;

    //constructing the graph
    int x,y,w;
    for(int i=0;i<e;i++)
        cin >> x >> y >> w, edges[x][y] = edges[y][x] = w;

    floyd_warshall(v);
}