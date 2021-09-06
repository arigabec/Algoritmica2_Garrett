#include <bits/stdc++.h> 
#define MAX_N 10000
#define INF 987654321
using namespace std;
typedef long long lld;

struct Node
{
    vector<int> adj;
};
Node graf[MAX_N];

struct Edge
{
    int u, v, cap;
    int flow;
};
vector<Edge> E;

int v, e;
int s, t;
int dist[MAX_N];
int upTo[MAX_N];
int idd = 0;

inline bool BFS()
{
    for (int i=1;i<=v;i++) dist[i] = -1;
    queue<int> bfs_queue;
    bfs_queue.push(s);
    dist[s] = 0;
    while (!bfs_queue.empty())
    {
        int xt = bfs_queue.front();
        bfs_queue.pop();
        for (int i=0;i<graf[xt].adj.size();i++)
        {
            int currID = graf[xt].adj[i];
            int xt1 = E[currID].v;
            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap)
            {
                bfs_queue.push(xt1);
                dist[xt1] = dist[xt] + 1;
            }
        }
    }
    return (dist[t] != -1);
}

inline int DFS(int xt, int minCap)
{
    if (minCap == 0) return 0;
    if (xt == t) return minCap;
    while (upTo[xt] < graf[xt].adj.size())
    {
        int currID = graf[xt].adj[upTo[xt]];
        int xt1 = E[currID].v;
        if (dist[xt1] != dist[xt] + 1)
        {
            upTo[xt]++;
            continue;
        }
        int aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
        if (aug > 0)
        {
            E[currID].flow += aug;
            if (currID&1) currID--; else currID++;
            E[currID].flow -= aug;
            return aug;
        }
        upTo[xt]++;
    }
    return 0;
}

inline int Dinic()
{
    int flow = 0;
    while (true)
    {
        if (!BFS()) break;
        for (int i=1;i<=v;i++) upTo[i] = 0;
        while (true)
        {
            int currFlow = DFS(s, INF);
            if (currFlow == 0) break;
            flow += currFlow;
        }
    }
    return flow;
}

inline void addEdge(int u, int v, int cap)
{
    Edge E1, E2;
    
    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
    
    graf[u].adj.push_back(idd++);
    E.push_back(E1);
    graf[v].adj.push_back(idd++);
    E.push_back(E2);
}

int main(){
	int cases = 1;
    while(cin >> v && v){
        cin >> s >> t >> e;
        for(int i = 0; i < e; i++){
            int from, to, capacity;
            cin >> from >> to >> capacity;
            addEdge(from, to, capacity);
        }
        cout << "Network " << cases++ << endl;
        cout << "The bandwidth is " << Dinic() << "." << endl << endl;
    }
    return 0;
}