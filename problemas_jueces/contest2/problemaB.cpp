#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX_V 1050
#define tipo long long
#define pb(i) push_back(i)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int cases, s, t, qt_vertex, qt_edges, qt_problems;
int res[MAX_V][MAX_V];
vi graph[MAX_V];
int mf, f, nc, np;
int work[MAX_V], dist[MAX_V];

int dinic_dfs(int u, int flow){
  if ( u== t){
    return flow;
  }
  for (int &i = work[u]; i < (int) graph[u].size(); i++){
    int v = graph[u][i];
    if (res[u][v] <= 0){
      continue;
    }
    if (dist[v] == dist[u] + 1){
      int df = dinic_dfs(v, min(flow, res[u][v]) );
      if (df > 0){
        res[u][v] -= df;
        res[v][u] += df;
        return df;
      } 
    }
  }
  return 0;
}

bool dinic_bfs(){
  memset(dist, -1, sizeof dist);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)graph[u].size(); i++){
      int v = graph[u][i];
      if (dist[v] < 0 && res[u][v]){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[t] >= 0;  
}

int maxFlow(){
  int result = 0;
  while(dinic_bfs()){
    memset(work, 0, sizeof work);
    while (int delta = dinic_dfs(s, INF)) result += delta;
  }
  return result;
}

void connect(int u, int v, int w){
  graph[u].pb(v);
  graph[v].pb(u);
  res[u][v] = w;
}

void init(){
  memset(res, 0, sizeof res);
  for (int i = 0; i < MAX_V; i++){
    graph[i].clear();
  }
  qt_problems = 0;
  s = 0;
  t = 1;
}

void read(){
  int limit, ncp, cat_num;
  for (int i = 0; i < nc; i++){
    scanf("%d", &limit);
    connect(i + 2, t, limit);
    qt_problems += limit;
  }
  for (int i = 0; i < np; i++){
    scanf("%d", &ncp); 
    for (int j = 0; j < ncp; j++){
      scanf("%d", &cat_num);
      connect(i + 22, cat_num + 1, 1);
    }
    connect(s, i + 22, 1);
  }
}

void solve(){
  mf = maxFlow();	
}

void printCategory(int c){
  int p;
  bool sp = 0;
  for (int i = 0; i < (int)graph[c].size(); i++){
    p = graph[c][i];
    if (p == t){
      continue;
    }
    if (res[c][p]){
      if (sp){
        printf(" %d", p-21);
      } else { 
        printf("%d", p-21); sp = 1;
      }
    }
  }
}

void output(){
  if (mf != qt_problems){
    printf("0\n");
  } else {
    printf("1\n");
    for (int i = 0; i < nc; i++){
      printCategory(i + 2);
      printf("\n");
    }
  }
}

int main(){
  while(scanf("%d %d", &nc, &np) && nc){
    init();
    read();
    solve();
    output();
  }
  return 0;
}