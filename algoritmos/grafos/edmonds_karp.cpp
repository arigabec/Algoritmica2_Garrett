#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101         

int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];           // camino b: b <- a     
// path 0->3->2->4    
// [0,-1,3,0,2,-1, 4]
//  0  1 2 3 4, 5, 6
// Edmonds Karp 
// DINIC 
int maxFlow(int s,int t) { 
    // s nodo inicial 
    // t nodo final 
    int maxFlow = 0;
    while(true){
        //BFS 
        memset(path, -1, sizeof(path));
        queue<int> Q;
        Q.push(s);
        path[s] = s; 
        while(!Q.empty() && path[t] == -1){
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++){
                if(path[i] == -1 && grafo[currentNode][i] > 0) {  // puedo visitar? 
                    path[i] = currentNode;                       // guardar camino 
                    Q.push(i);                                  // agregar a la cola
                }   
            }
        }
        int minFlow = 1e9;
        if(path[t]==-1){
            break;
        }
        for(int from = path[t], to = t; from != to ; from = path[to = from]){
            minFlow = min(minFlow,grafo[from][to]);
        }
        // Sumar y restar ese minimo                                            // sumar todos os diferentes a -1 
        for(int from = path[t], to = t; from != to ; from = path[to = from]){
            grafo[from][to] -= minFlow;
            grafo[to][from] += minFlow;
        }
        maxFlow += minFlow;
    }
    return maxFlow;
}

int main() {
    int nodes, aristas, nroCases = 1; 
    while(cin >> nodes && nodes){
        int s, t; 
        cin >> s >> t >> aristas;
        memset(grafo, 0, sizeof(grafo));
        for(int i = 0; i < aristas; i++){
            int from, to, capacity; 
            cin >> from >> to >> capacity;
            grafo[from][to] = capacity;          // camino capacidad
            grafo[to][from] = 0;                //  flujo grafo residual 
        }
        cout << maxFlow(s,t) << endl;
    }    
}

/*7
8 10 11
8 4 10
8 9 2
8 5 8
4 6 10
4 9 6
5 9 1
5 7 3
6 10 5
9 10 9
7 9 7
7 10 5*/