//EDMONDS KARP

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
    int docentes, aristas; 
    cin >> docentes >> aristas;
    int nodos = 12;
    while(nodos){
        int s = 0;
        int t = 5;
        memset(grafo, 0, sizeof(grafo));
        for(int i = 0; i < aristas; i++){
            int from, to;
            int capacity = 1; 
            cin >> from >> to;
            grafo[from][to] = capacity;          // camino capacidad
            grafo[to][from] = 0;          //  flujo grafo residual 
        }
        cout << maxFlow(s,t) << endl;
    }    
}

/*
//Nro de docentes, nro de aristas (contanto las que van a 0 y a 5)
4 18
//Iniciamos el grafo en 0 (source) y conectamos con todos los docentes
0 1
0 2
0 3
0 4
//Conectamos a los docentes con las materias que pueden dar 
1 100 
1 102
1 103
2 100
2 105
3 200
3 203
4 103
//Conectamos las materias con el grafo 5 (terminal)
100 5
102 5
103 5
105 5
200 5
203 5
*/