#include <bits/stdc++.h>
using namespace std;
int V;

int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){
        if (mstSet[v] == false && key[v] < min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printPRIM(int parent[]){
    for (int i = 1; i < V; i++){
        cout << parent[i] + 1 << " " << i + 1 << endl;
    }
}
 
void prim(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++){
        int a = minKey(key, mstSet);
        mstSet[a] = true;
        for (int b = 0; b < V; b++){
            if (graph[a][b] && mstSet[b] == false && graph[a][b] < key[b]){
                parent[b] = a, key[b] = graph[a][b];
            }
        }      
    }
    printPRIM(parent);
}
 
int main(){
    cin >> V;
    int graph[V][V];
    for (int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }
    prim(graph);
    return 0;
}