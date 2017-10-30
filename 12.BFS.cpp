#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


class Graph{

    vector<vector<int>> edge;
    vector<int> visited;

public:

    Graph(int v)
    {
        edge.resize(v);
        visited.resize(v);
        for(int i=0;i<v;i++)
            visited[i] = -1;
    }

    void add_edge(int v, int u)
    {
        //adding from both directions makes it undirected
        edge[v].push_back(u);
        edge[u].push_back(v);
    }

    void BFS(int s) //bfs operation
    {
        queue<int> q;
        visited[s] = 1;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            cout << s << "* ";
            q.pop();
            for(int i=0; i<edge[s].size() ;i++)
            {
                if(visited[edge[s][i]] != 1)
                {
                    visited[edge[s][i]] = 1;
                    q.push(edge[s][i]);
                }
            }
        }
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices you want to add" << endl;
    cin >> v;

    int e;
    cout << "Enter the number of edges you want to add" << endl;
    cin >> e;

    Graph g(v);

    cout << "Enter the edges" << endl;
    int u,w;
    for(int i=0;i<e;i++)
        cin >> u >> w, g.add_edge(u,w);

    g.BFS(0); //starting BFS from vertex 0
}