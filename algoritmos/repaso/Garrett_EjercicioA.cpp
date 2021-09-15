#include <bits/stdc++.h>
using namespace std; 
#define MAX_N 101         

int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];           // camino b: b <- a     

int maxFlow(int s,int t) { 
    int maxFlow = 0;
    while(true){
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
        for(int from = path[t], to = t; from != to ; from = path[to = from]){
            grafo[from][to] -= minFlow;
            grafo[to][from] += minFlow;
        }
        maxFlow += minFlow;
    }
    return maxFlow;
}

int main() {
    int ninos, juguetes, categorias, k, l, r;
    cin >> ninos >> juguetes >> categorias;
    int s = 0, t = 5;
    memset(grafo, 0, sizeof(grafo));
    for (int i = 1; i <= ninos; i++){
        grafo[s][i] = 1;        
        grafo[i][s] = 0;
        cin >> k;
        while (k--){
            int to;
            cin >> to;
            grafo[i][to] = 1;
            grafo[to][i] = 0;
        }             
    }
    for (int i = 1; i <= categorias; i++){
        cin >> l;
        while (l--){
            int to;
            cin >> to;
            grafo[to][i] = 1;
            grafo[i][to] = 0;
        }
        cin >> r;
        grafo[categorias][t] = r;        
        grafo[t][categorias] = 0;
        if(l != juguetes){
            grafo[juguetes][t] = 1;
            grafo[t][juguetes] = 0;
        }
    }
    cout << maxFlow(s,t) << endl;
}

/*
4 3 1
2 1 2
2 1 2
1 3
1 3
2 1 2 1
*/