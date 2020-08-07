#include<iostream>
#include<list>
#include<cstring>
#include<cstdio>
using namespace std;
int flag = 1;

class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[1000001];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    string *color = new string[1000001];
    for(int i=0;i<V;i++)
        visited[i] = false;
    list<int> queue;
    queue.push_back(s);
    visited[s] = true;
    color[s] = "red";
    list<int>::iterator i;
    flag = 1;
    while(!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                if(color[s] == "red")
                    color[*i] = "blue";
                if(color[s] == "blue")
                    color[*i] = "red";
                queue.push_back(*i);
            }
            else
            {
                if(color[s] == color[*i])
                    flag = 0;
            }
        }
    }
}


int main()
{
    int T, bugs, edges, from, to;
    scanf("%d", &T);
    int p = T;
    while(T--)
    {
        scanf("%d%d", &bugs, &edges);
        Graph g(bugs+1);
        for(int i=0; i<edges; i++)
        {
            scanf("%d%d", &from, &to);
            g.addEdge(from, to);
        }

        g.BFS(from);

        if(!flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n", p-T);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n", p-T);

    }


    return 0;
}